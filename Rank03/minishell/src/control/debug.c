#include "minishell.h"

void	debug_int(t_smash *smash, char *variable, int value)
{
	if (!smash->debug_mode || !variable)
		return ;
	ft_putstr_fd("\e[3;33m", STDERR_FILENO);
	ft_putstr_fd(variable, STDERR_FILENO);
	ft_putstr_fd(" -> ", STDERR_FILENO);
	ft_putnbr_fd(value, STDERR_FILENO);
	ft_putendl_fd("\e[0m", STDERR_FILENO);
}

void	debug_string(t_smash *smash, char *variable, char *value)
{
	if (!smash->debug_mode || !variable)
		return ;
	if (!value)
		return (debug_string(smash, variable, PRINT_NULL_STRING));
	ft_putstr_fd("\e[3;33m", STDERR_FILENO);
	ft_putstr_fd(variable, STDERR_FILENO);
	ft_putstr_fd(" -> ", STDERR_FILENO);
	ft_putstr_fd(value, STDERR_FILENO);
	ft_putendl_fd("\e[0m", STDERR_FILENO);
}

void	debug_tokens(t_smash *smash)
{
	t_token	*iter;

	if (!smash->debug_mode)
		return ;
	ft_putstr_fd("\e[3;33m", STDERR_FILENO);
	iter = smash->first_token;
	while (iter)
	{
		ft_putstr_fd("Token: ", STDERR_FILENO);
		if (iter->type == INPUT)
			ft_putendl_fd("<", STDERR_FILENO);
		else if (iter->type == HEREDOC)
			ft_putendl_fd("<<", STDERR_FILENO);
		else if (iter->type == OUTPUT)
			ft_putendl_fd(">", STDERR_FILENO);
		else if (iter->type == APPEND)
			ft_putendl_fd(">>", STDERR_FILENO);
		else if (iter->type == PIPE)
			ft_putendl_fd("|", STDERR_FILENO);
		else
			ft_putendl_fd(iter->value, STDERR_FILENO);
		iter = iter->next;
	}
	ft_putstr_fd("\e[0m", STDERR_FILENO);
}

void	debug_pipelines(t_smash *smash)
{
	t_pipeline	*iter;
	int			i;

	if (!smash->debug_mode)
		return ;
	ft_putstr_fd("\e[3;33m", STDERR_FILENO);
	iter = smash->first_pipeline;
	while (iter)
	{
		ft_printf_fd(STDERR_FILENO, "Pipeline: \nfd in: %i\nfd out: %i\ncmd:\n",
			iter->fd_in, iter->fd_out);
		i = 0;
		while (iter->cmd[i])
			ft_printf_fd(STDERR_FILENO, "\t%s\n", iter->cmd[i++]);
		iter = iter->next;
	}
	ft_putstr_fd("\e[0m", STDERR_FILENO);
}
