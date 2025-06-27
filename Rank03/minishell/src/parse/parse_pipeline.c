#include "minishell.h"

static t_pipeline	*new_pipeline(t_token *current);
static int			get_cmd_num(t_token *current);
static bool			add_redirection(t_pipeline *pipelst, t_token **current);
static void			pipe_add_back(t_pipeline *new, t_pipeline **pipelst);

bool	parse_pipeline(t_smash *smash)
{
	t_pipeline	*pipelst;
	t_token		*current;
	t_pipeline	*new;

	pipelst = NULL;
	current = smash->first_token;
	while (current)
	{
		new = new_pipeline(current);
		if (!new)
			return (false);
		pipe_add_back(new, &pipelst);
		while (current && current->type != PIPE)
			current = current->next;
		if (current && current->type == PIPE)
			current = current->next;
	}
	smash->first_pipeline = pipelst;
	return (true);
}

static t_pipeline	*new_pipeline(t_token *current)
{
	int			cmd_num;
	int			i;
	t_pipeline	*new_pipeline;

	cmd_num = get_cmd_num(current);
	i = 0;
	new_pipeline = ft_calloc(1, sizeof(t_pipeline));
	if (!new_pipeline)
		return (NULL);
	new_pipeline->cmd = ft_calloc(cmd_num + 1, sizeof(char *));
	if (!new_pipeline->cmd)
		return (free(new_pipeline), NULL);
	new_pipeline->fd_out = STDOUT_FILENO;
	while (current && current->type != PIPE)
	{
		if (!is_redirection(current->type))
		{
			new_pipeline->cmd[i++] = current->value;
			current = current->next;
		}
		else if (!add_redirection(new_pipeline, &current))
			return (free_pipeline(new_pipeline), NULL);
	}
	return (new_pipeline);
}

static int	get_cmd_num(t_token *token)
{
	int		cmd_num;
	t_token	*before;

	cmd_num = 0;
	before = NULL;
	while (token && token->type != PIPE)
	{
		if (is_word(token->type) && (!before || !is_redirection(before->type)))
			cmd_num++;
		before = token;
		token = token->next;
	}
	return (cmd_num);
}

static bool	add_redirection(t_pipeline *pipelst, t_token **current)
{
	t_redir	*redir;
	t_redir	*aux;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (false);
	redir->type = (*current)->type;
	redir->value = (*current)->next->value;
	redir->fd = -1;
	redir->next = NULL;
	if (!pipelst->redir_lst)
		pipelst->redir_lst = redir;
	else
	{
		aux = pipelst->redir_lst;
		while (aux->next)
			aux = aux->next;
		aux->next = redir;
	}
	*current = (*current)->next->next;
	return (true);
}

static void	pipe_add_back(t_pipeline *new, t_pipeline **pipelst)
{
	t_pipeline	*last;

	if (!*pipelst)
	{
		*pipelst = new;
		return ;
	}
	last = *pipelst;
	while (last->next)
		last = last->next;
	last->next = new;
}
