#include "minishell.h"

static char	**get_env_path(t_smash *smash);
static void	error_message(t_exit_code *exit_value, char *cmd_path, char *cmd_0);

void	execute_external(t_smash *smash, t_pipeline *pipeline)
{
	char		**path;
	char		*command;
	char		**env_char;
	t_exit_code	exit_code;

	command = NULL;
	exit_code = EC_SUCCESS;
	path = get_env_path(smash);
	command = get_command(path, pipeline->cmd[0], &exit_code);
	env_char = env_to_char(smash->envp);
	if (exit_code == EC_SUCCESS)
		execve(command, pipeline->cmd, env_char);
	error_message(&exit_code, command, pipeline->cmd[0]);
	ft_free_double_pointer((void **) path);
	ft_free_double_pointer((void **) env_char);
	free(command);
	smash->exit_status = exit_code;
}

static char	**get_env_path(t_smash *smash)
{
	char	*env_path;

	env_path = get_value(smash->envp, "PATH");
	if (!env_path)
		return (NULL);
	return (ft_split(env_path, ':'));
}

static void	error_message(t_exit_code *exit_value, char *cmd_path, char *cmd_0)
{
	if (*exit_value == EC_SUCCESS)
	{
		ft_printf_fd(STDERR_FILENO, "smash: %s: Is a directory\n", cmd_path);
		*exit_value = EC_COMMAND_NOT_EXECUTABLE;
	}
	else if (*exit_value == EC_FILE_NOT_FOUND)
	{
		ft_printf_fd(STDERR_FILENO,
			"smash: %s: No such file or directory\n", cmd_0);
		*exit_value = EC_COMMAND_NOT_FOUND;
	}
	else if (*exit_value == EC_COMMAND_NOT_EXECUTABLE)
		ft_printf_fd(STDERR_FILENO, "smash: %s: Permission denied\n", cmd_path);
	else if (*exit_value == EC_COMMAND_NOT_FOUND)
		ft_printf_fd(STDERR_FILENO, "smash: %s: command not found\n", cmd_0);
}
