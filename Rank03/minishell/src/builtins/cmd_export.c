#include "minishell.h"

static void	custom_prompt(char	**entry);
static bool	has_valid_args(char **input);
static bool	add_entry(t_smash *smash, char	**entry);

int	cmd_export(t_smash *smash, char **input)
{
	int		i;
	char	**entry;
	int		returnvalue;

	i = 1;
	returnvalue = 0;
	if (!has_valid_args(input))
		return (2);
	while (input[i])
	{
		if (!is_valid_key(input[i]))
		{
			returnvalue = 1;
			ft_printf_fd(2, "smash: export: '%s': not a valid identifier\n",
				input[i++]);
			continue ;
		}
		entry = split_char(input[i++], '=');
		custom_prompt(entry);
		if (entry && !add_entry(smash, entry))
			return (ft_free_double_pointer((void **)entry),
				ft_putstr_fd("Internal error\n", 2), -1);
		ft_free_double_pointer((void **)entry);
	}
	return (returnvalue);
}

static void	custom_prompt(char	**entry)
{
	char	*aux;

	if (entry
		&& (ft_str_equals(entry[0], "PS1") || ft_str_equals(entry[0], "PS2"))
		&& entry[1])
	{
		aux = parse_octals_prompt(entry[1]);
		free(entry[1]);
		entry[1] = aux;
	}
}

static bool	add_entry(t_smash *smash, char **entry)
{
	if (!get_value(smash->envp, entry[0]))
		if (!new_entry(&(smash->envp), entry[0], entry[1]))
			return (false);
	if (!update_envp(&(smash->envp), entry[0], entry[1]))
		return (false);
	return (true);
}

static bool	has_valid_args(char **input)
{
	if (input[1] && !ft_strncmp(input[1], "-", 1))
		return (ft_putstr_fd("smash: export: -: invalid option\n", 2), false);
	if (!input[1])
		return (ft_putstr_fd("smash: export: missing operand\n", 2), false);
	return (true);
}
