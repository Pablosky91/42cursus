#include "minishell.h"

bool	execute_builtins(t_smash *smash, t_pipeline *pipeline)
{
	if (ft_str_equals(pipeline->cmd[0], "env"))
		smash->exit_status = cmd_env(*smash, pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "pwd"))
		smash->exit_status = cmd_pwd(smash, pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "unset"))
		smash->exit_status = cmd_unset(smash, pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "export"))
		smash->exit_status = cmd_export(smash, pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "echo"))
		smash->exit_status = cmd_echo(pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "cd"))
		smash->exit_status = cmd_cd(smash, pipeline->cmd);
	else if (ft_str_equals(pipeline->cmd[0], "exit"))
		smash->exit_status = cmd_exit(smash, pipeline->cmd);
	else
		return (false);
	if (smash->exit_status == -1)
		return (false);
	return (true);
}
