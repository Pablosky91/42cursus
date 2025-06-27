#include "minishell.h"

char	*get_value(t_envp *envp, char *key)
{
	while (envp)
	{
		if (ft_str_equals(envp->key, key))
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}

bool	new_entry(t_envp **envp, char *key, char *value)
{
	t_envp	*node;

	node = new_node(key, value);
	if (!node)
		return (false);
	addnode_front(node, envp);
	return (true);
}

bool	update_envp(t_envp **envp, char *key, char *newvalue)
{
	t_envp	*current;

	if (!get_value(*envp, key))
		return (false);
	current = *envp;
	while (current)
	{
		if (ft_str_equals(current->key, key))
		{
			free(current->value);
			current->value = ft_strdup(newvalue);
			if (!current->value)
				return (false);
			return (true);
		}
		current = current->next;
	}
	return (true);
}

void	display_envp(t_envp *envp)
{
	while (envp)
	{
		ft_printf("%s=%s\n", envp->key, envp->value);
		envp = envp->next;
	}
}

t_envp	*init_envp(char **envp)
{
	int		i;
	char	**sp_envp;
	t_envp	*struct_envp;

	i = 0;
	struct_envp = NULL;
	while (envp[i])
	{
		sp_envp = split_char(envp[i], '=');
		if (!sp_envp || !new_entry(&struct_envp, sp_envp[0], sp_envp[1]))
			return (ft_free_double_pointer((void **)sp_envp), NULL);
		ft_free_double_pointer((void **)sp_envp);
		i++;
	}
	return (struct_envp);
}
