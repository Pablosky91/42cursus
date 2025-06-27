#include "minishell.h"

static void	handle_sigint(int sig);

bool	sig_handler(t_smash	*smash)
{
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		smash->error_type = INTERNAL;
		return (false);
	}
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		smash->error_type = INTERNAL;
		return (false);
	}
	return (true);
}

static void	handle_sigint(int sig)
{
	(void) sig;
	g_sigint_heredoc = true;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}
