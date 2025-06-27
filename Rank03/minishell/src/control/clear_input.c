#include "minishell.h"

static void	free_pipelines(t_pipeline *pipeline);
static void	free_redirs(t_redir *redir);

void	clear_input(t_smash *smash)
{
	free_tokens(smash->first_token);
	free_pipelines(smash->first_pipeline);
	free(smash->user_input);
	smash->first_token = NULL;
	smash->last_token = NULL;
	smash->first_pipeline = NULL;
	smash->user_input = NULL;
	if (g_sigint_heredoc)
		smash->exit_status = 130;
	g_sigint_heredoc = false;
}

void	free_tokens(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		free_token(token);
		token = next;
	}
}

void	free_token(t_token *token)
{
	t_var	*var;
	t_var	*next;

	var = token->first_variable;
	while (var)
	{
		next = var->next;
		free(var->value);
		free(var);
		var = next;
	}
	free(token->value);
	free(token);
}

static void	free_pipelines(t_pipeline *pipeline)
{
	t_pipeline	*next;

	while (pipeline)
	{
		next = pipeline->next;
		if (pipeline->fd_in != STDIN_FILENO && pipeline->fd_in != -1)
			close(pipeline->fd_in);
		if (pipeline->fd_out != STDOUT_FILENO && pipeline->fd_out != -1)
			close(pipeline->fd_out);
		free_redirs(pipeline->redir_lst);
		free(pipeline->cmd);
		free(pipeline);
		pipeline = next;
	}
}

static void	free_redirs(t_redir *redir)
{
	t_redir	*next;

	while (redir)
	{
		next = redir->next;
		free(redir);
		redir = next;
	}
}
