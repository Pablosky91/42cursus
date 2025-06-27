#include "minishell.h"

static void	history_file_name(t_smash *smash);

void	import_history(t_smash *smash)
{
	char	*line;
	bool	end;
	int		fd;

	if (smash->debug_mode)
		return ;
	history_file_name(smash);
	if (!smash->history_file)
		return ;
	fd = open(smash->history_file, O_RDONLY);
	if (fd < 0)
		return ;
	end = false;
	while (!end)
	{
		line = ft_get_next_line_no_nl(fd);
		if (!line)
			end = true;
		if (!end && line[0])
			add_history(line);
		free(line);
	}
	close(fd);
}

void	add_history_entry(t_smash *smash)
{
	int	fd;

	if (smash->debug_mode)
		return ;
	if (smash->user_input && !smash->user_input[0])
		return ;
	add_history(smash->user_input);
	if (!smash->history_file)
		return ;
	fd = open(smash->history_file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd < 0)
		return ;
	ft_putendl_fd(smash->user_input, fd);
	close(fd);
}

static void	history_file_name(t_smash *smash)
{
	char	*home;

	home = getenv("HOME");
	if (home)
		smash->history_file = ft_strjoin(home, "/.smash_history");
	if (!smash->history_file)
		smash->history_file = ft_strdup(".smash_history");
}
