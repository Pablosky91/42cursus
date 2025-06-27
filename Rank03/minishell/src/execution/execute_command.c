#include "minishell.h"

static void	execute_child(t_smash *smash, t_pipeline *pipeline);
static void	close_unused_fds(t_smash *smash, t_pipeline *pipeline);
static bool	backup_std_fds(t_smash *smash, t_pipeline *pipeline);
static bool	restore_std_fds(t_smash *smash);

bool	execute_command(t_smash *smash, t_pipeline *pipeline, pid_t *pid)
{
	smash->fd_stdin = -1;
	smash->fd_stdout = -1;
	if (!smash->first_pipeline->next
		&& (pipeline->fd_in < 0 || pipeline->fd_out < 0 || !pipeline->cmd[0]))
	{
		if (pipeline->fd_in < 0 || pipeline->fd_out < 0)
			smash->exit_status = 1;
		return (true);
	}
	if (!backup_std_fds(smash, pipeline))
		return (false);
	if (smash->first_pipeline->next || !execute_builtins(smash, pipeline))
	{
		*pid = fork();
		if (*pid == -1)
		{
			restore_std_fds(smash);
			return (false);
		}
		signal(SIGINT, SIG_IGN);
		if (*pid == 0)
			execute_child(smash, pipeline);
	}
	return (restore_std_fds(smash));
}

static void	execute_child(t_smash *smash, t_pipeline *pipeline)
{
	int	exit_status;

	exit_status = 0;
	sig_handler(smash);
	if (pipeline->fd_in < 0 || pipeline->fd_out < 0 || !pipeline->cmd[0])
	{
		if (pipeline->fd_in < 0 || pipeline->fd_out < 0)
			exit_status = 1;
		free_smash(*smash);
		exit(exit_status);
	}
	close_unused_fds(smash, pipeline);
	if (!execute_builtins(smash, pipeline))
		execute_external(smash, pipeline);
	exit_status = smash->exit_status;
	free_smash(*smash);
	exit(exit_status);
}

static void	close_unused_fds(t_smash *smash, t_pipeline *pipeline)
{
	t_pipeline	*iter;

	if (smash->fd_stdin != -1)
		close(smash->fd_stdin);
	if (smash->fd_stdout != -1)
		close(smash->fd_stdout);
	iter = smash->first_pipeline;
	while (iter)
	{
		if (iter != pipeline)
		{
			if (iter->fd_in != STDIN_FILENO && iter->fd_in != -1)
				close(iter->fd_in);
			if (iter->fd_out != STDOUT_FILENO && iter->fd_out != -1)
				close(iter->fd_out);
		}
		iter = iter->next;
	}
}

static bool	backup_std_fds(t_smash *smash, t_pipeline *pipeline)
{
	if (pipeline->fd_in != STDIN_FILENO && pipeline->fd_in >= 0)
	{
		smash->fd_stdin = dup(STDIN_FILENO);
		if (smash->fd_stdin == -1)
			return (false);
		if (dup2(pipeline->fd_in, 0) == -1 || close(pipeline->fd_in) == -1)
			return (close(smash->fd_stdin), false);
	}
	if (pipeline->fd_out != STDOUT_FILENO && pipeline->fd_out >= 0)
	{
		smash->fd_stdout = dup(STDOUT_FILENO);
		if (smash->fd_stdout == -1)
		{
			if (smash->fd_stdin != -1)
				close(smash->fd_stdin);
			return (false);
		}
		if (dup2(pipeline->fd_out, 1) == -1 || close(pipeline->fd_out) == -1)
		{
			if (smash->fd_stdin != -1)
				close(smash->fd_stdin);
			return (close(smash->fd_stdout), false);
		}
	}
	return (true);
}

static bool	restore_std_fds(t_smash *smash)
{
	bool	ok;

	ok = true;
	if (smash->fd_stdin != -1)
	{
		if (dup2(smash->fd_stdin, STDIN_FILENO) == -1)
			ok = false;
		if (close(smash->fd_stdin) == -1)
			ok = false;
	}
	if (smash->fd_stdout != -1)
	{
		if (dup2(smash->fd_stdout, STDOUT_FILENO) == -1)
			ok = false;
		if (close(smash->fd_stdout) == -1)
			ok = false;
	}
	return (ok);
}
