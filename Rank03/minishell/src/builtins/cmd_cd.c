#include "minishell.h"

static bool	update_wd(t_smash *smash);

int	cmd_cd(t_smash *smash, char **input)
{
	if (input[1] && input[2])
		return (ft_printf_fd(2, "smash: cd: too many arguments\n"), 1);
	if (!input[1])
	{
		if (!get_value(smash->envp, "HOME"))
			return (ft_printf_fd(2, "smash: cd: HOME is not set\n"), 1);
		if (chdir(get_value(smash->envp, "HOME")) == -1)
			return (1);
		update_wd(smash);
		return (0);
	}
	if (ft_strncmp(input[1], "-", 1) == 0)
		return (ft_printf_fd(2, "smash: cd: -: invalid option\n"), 2);
	if (access(input[1], F_OK | X_OK) == -1)
		return (ft_printf_fd(2, "smash: cd: %s: No such file or directory\n",
				input[1]), 1);
	if (chdir(input[1]) == -1)
		return (1);
	if (!update_wd(smash))
		ft_printf_fd(2, "smash: can't set PWD or OLDPWD variable\n");
	return (0);
}

static bool	update_wd(t_smash *smash)
{
	update_envp(&smash->envp, "OLDPWD", get_value(smash->envp, "PWD"));
	if (smash->cwd)
		free(smash->cwd);
	smash->cwd = getcwd(NULL, 0);
	if (get_value(smash->envp, "PWD") && smash->cwd)
		return (update_envp(&smash->envp, "PWD", smash->cwd));
	return (false);
}
