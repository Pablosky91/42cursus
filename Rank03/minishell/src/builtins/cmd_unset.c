#include "minishell.h"

int	cmd_unset(t_smash *smash, char **input)
{
	int	i;

	i = 1;
	if (!smash->envp)
		return (1);
	if (input[1] && !ft_strncmp(input[1], "-", 1))
		return (ft_putstr_fd("smash: unset: -: invalid option\n", 2), 2);
	while (input[i])
	{
		if (get_value(smash->envp, input[i]))
			free_node(&(smash->envp), input[i]);
		i++;
	}
	return (0);
}
