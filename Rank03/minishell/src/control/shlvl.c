#include "minishell.h"

bool	shlvl(t_smash *smash)
{
	int		num;
	char	*itoa;
	bool	ok;

	if (!get_value(smash->envp, "SHLVL"))
		return (new_entry(&(smash->envp), "SHLVL", "1"));
	else if (ft_atoi_better(get_value(smash->envp, "SHLVL"), &num))
	{
		if (num < 0)
			num = 0;
		num++;
	}
	else
		num = 1;
	if (num >= 1000)
	{
		ft_printf_fd(2,
			"smash: warning: shell level (1000) too high, resetting to 1\n");
		num = 1;
	}
	itoa = ft_itoa(num);
	if (!itoa)
		return (false);
	ok = update_envp(&(smash->envp), "SHLVL", itoa);
	return (free(itoa), ok);
}
