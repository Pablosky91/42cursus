#include "minishell.h"

bool	g_sigint_heredoc = false;

static t_smash	init(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_smash	smash;

	smash = init(argc, argv, envp);
	if (smash.exit_status == 1)
		return (free_smash(smash), ft_putstr_fd("Internal error\n", 2), 1);
	while (true)
	{
		if (!sig_handler(&smash))
			break ;
		parse_line(&smash);
		if (smash.error_type != OK)
		{
			if (smash.error_type == CTRL_D || smash.error_type == INTERNAL)
				break ;
			else
				continue ;
		}
		if (!execute(&smash))
			break ;
	}
	if (smash.error_type == INTERNAL)
		ft_printf_fd(2, "Internal error\n");
	cmd_exit(&smash, NULL);
	return (0);
}

static t_smash	init(int argc, char **argv, char **envp)
{
	t_smash	smash;

	smash.debug_mode = argc > 1 && ft_str_equals(argv[1], "debug");
	smash.exit_status = 0;
	smash.envp = init_envp(envp);
	smash.cwd = getcwd(NULL, 0);
	if (!smash.envp || !smash.cwd || !shlvl(&smash))
		smash.exit_status = 1;
	smash.user_input = NULL;
	smash.first_token = NULL;
	smash.last_token = NULL;
	smash.first_pipeline = NULL;
	smash.history_file = NULL;
	smash.error_type = OK;
	import_history(&smash);
	return (smash);
}
