#include "minishell.h"

static bool	open_heredoc(t_smash *smash, t_redir *redir);
static bool	heredoc_loop(t_smash *smash, t_token *token, int *fds, char *delim);
static void	open_fd(t_pipeline *pipeline, t_redir *redir);
static void	handle_fd(t_smash *smash);

bool	handle_redirections(t_smash *smash)
{
	t_pipeline	*pipeline;
	t_redir		*redir;

	pipeline = smash->first_pipeline;
	while (pipeline)
	{
		redir = pipeline->redir_lst;
		while (redir)
		{
			if (!open_heredoc(smash, redir))
				return (false);
			redir = redir->next;
		}
		pipeline = pipeline->next;
	}
	handle_fd(smash);
	return (true);
}

static void	handle_fd(t_smash *smash)
{
	t_pipeline	*pipeline;
	t_redir		*redir;

	pipeline = smash->first_pipeline;
	while (pipeline)
	{
		redir = pipeline->redir_lst;
		while (redir)
		{
			open_fd(pipeline, redir);
			redir = redir->next;
		}
		pipeline = pipeline->next;
	}
}

static bool	open_heredoc(t_smash *smash, t_redir *redir)
{
	int		fds[2];
	t_token	*head;
	bool	ok;

	if (redir->type != HEREDOC)
		return (true);
	head = ft_calloc(1, sizeof(t_token));
	if (!head)
		return (false);
	if (pipe(fds) == -1)
		return (free(head), false);
	ok = heredoc_loop(smash, head, fds, redir->value);
	if (!ok)
		close(fds[PIPE_READ]);
	else
		redir->fd = fds[PIPE_READ];
	close(fds[PIPE_WRITE]);
	free_tokens(head);
	return (ok);
}

static bool	heredoc_loop(t_smash *smash, t_token *token, int *fds, char *delim)
{
	while (true)
	{
		if (g_sigint_heredoc)
			break ;
		token->value = prompt(smash, true);
		if (!token->value || ft_str_equals(delim, token->value))
			break ;
		if (!expand_token(smash, token, true))
			return (false);
		ft_printf_fd(fds[PIPE_WRITE], "%s\n", token->value);
		token->next = ft_calloc(1, sizeof(t_token));
		if (!token->next)
			return (false);
		token = token->next;
	}
	return (true);
}

static void	open_fd(t_pipeline *pipeline, t_redir *redir)
{
	errno = 0;
	if ((pipeline->fd_in == -1 || pipeline->fd_out == -1) && redir->fd != -1)
		close(redir->fd);
	if (pipeline->fd_in == -1 || pipeline->fd_out == -1)
		return ;
	if (redir->type == INPUT)
		redir->fd = open(redir->value, O_RDONLY);
	else if (redir->type == OUTPUT)
		redir->fd = open(redir->value, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->type == APPEND)
		redir->fd = open(redir->value, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (redir->fd < 0)
		ft_printf_fd(2, "smash: %s: %s\n", redir->value, strerror(errno));
	if ((redir->type == INPUT || redir->type == HEREDOC)
		&& pipeline->fd_in != STDIN_FILENO)
		close(pipeline->fd_in);
	if (redir->type == INPUT || redir->type == HEREDOC)
		pipeline->fd_in = redir->fd;
	if ((redir->type == OUTPUT || redir->type == APPEND)
		&& pipeline->fd_out != STDOUT_FILENO)
		close(pipeline->fd_out);
	if (redir->type == OUTPUT || redir->type == APPEND)
		pipeline->fd_out = redir->fd;
	errno = 0;
}
