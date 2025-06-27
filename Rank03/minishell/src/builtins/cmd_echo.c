#include "minishell.h"

static bool	no_newline(char *str);

int	cmd_echo(char **input)
{
	int		i;
	bool	nl;

	i = 1;
	nl = true;
	while (input[i] && no_newline(input[i]))
	{
		nl = false;
		i++;
	}
	while (input[i])
	{
		ft_printf("%s", input[i]);
		i++;
		if (input[i])
			ft_printf(" ");
	}
	if (nl)
		ft_printf("\n");
	return (0);
}

static bool	no_newline(char *str)
{
	int	i;

	if (str[0] != '-')
		return (false);
	i = 1;
	while (str[i])
		if (str[i++] != 'n')
			return (false);
	return (true);
}
