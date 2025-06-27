#include "minishell.h"

static bool	open_pipes(t_pipeline *pipeline);
static void	wait_children(t_smash *smash, pid_t last_child);

bool	execute(t_smash *smash)
{
	t_pipeline	*pipeline;
	pid_t		pid;

	pid = INIT_PID;
	if (!open_pipes(smash->first_pipeline) || !handle_redirections(smash))
		smash->error_type = INTERNAL;
	pipeline = smash->first_pipeline;
	while (smash->error_type != INTERNAL && pipeline && !g_sigint_heredoc)
	{
		if (!execute_command(smash, pipeline, &pid))
			smash->error_type = INTERNAL;
		pipeline = pipeline->next;
	}
	clear_input(smash);
	wait_children(smash, pid);
	return (smash->error_type != INTERNAL);
}

static bool	open_pipes(t_pipeline *pipeline)
{
	int			fds[2];

	while (pipeline->next)
	{
		if (pipe(fds) == -1)
			return (false);
		pipeline->fd_out = fds[PIPE_WRITE];
		pipeline->next->fd_in = fds[PIPE_READ];
		pipeline = pipeline->next;
	}
	return (true);
}

static void	wait_children(t_smash *smash, pid_t last_child)
{
	int		status;
	pid_t	pid;

	pid = 0;
	status = -1;
	while (true)
	{
		pid = wait(&status);
		if (pid == -1)
			break ;
		if (pid == last_child)
			smash->exit_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
		{
			ft_printf("\n");
			smash->exit_status = WTERMSIG(status) + 128;
		}
	}
}
