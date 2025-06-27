#include "minishell.h"

int	cmd_exit(t_smash *smash, char **input)
{
	int	num;

	num = 0;
	ft_printf("exit\n");
	if (input)
	{
		if (input[1] && input[2])
			return (ft_printf_fd(2, "smash: exit: too many arguments\n"), 1);
		if (input[1] && !ft_atoi_better(input[1], &num))
		{
			ft_printf_fd(2,
				"smash: exit: %s: numeric argument required\n", input[1]);
			num = 2;
		}
	}
	free_smash(*smash);
	exit(num);
	return (0);
}
