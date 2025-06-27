#include "minishell.h"

void	free_t_envp(t_envp *envp)
{
	t_envp	*tmp;

	while (envp)
	{
		free(envp->key);
		free(envp->value);
		tmp = envp;
		envp = envp->next;
		free(tmp);
	}
	free(envp);
}

void	free_smash(t_smash smash)
{
	clear_input(&smash);
	free_t_envp(smash.envp);
	free(smash.cwd);
	free(smash.history_file);
	smash.envp = NULL;
	smash.cwd = NULL;
	smash.history_file = NULL;
	rl_clear_history();
}

bool	free_node(t_envp **envp, char *key)
{
	t_envp	*current;
	t_envp	*prev;

	current = *envp;
	prev = NULL;
	while (current)
	{
		if (ft_str_equals(current->key, key))
		{
			if (prev == NULL)
				*envp = current->next;
			else
				prev->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return (true);
		}
		prev = current;
		current = current->next;
	}
	return (false);
}

void	free_redir(t_redir *redir)
{
	while (redir)
	{
		free(redir->value);
		redir = redir->next;
	}
	free(redir);
}

void	free_pipeline(t_pipeline *pipeline)
{
	free(pipeline->cmd);
	free_redir(pipeline->redir_lst);
	free(pipeline);
}
