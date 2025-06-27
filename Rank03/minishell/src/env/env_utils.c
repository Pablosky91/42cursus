#include "minishell.h"

char	**split_char(char *envp, char c)
{
	int		keysize;
	char	*key;
	char	*value;
	char	*delimiter_position;
	char	**splitted;

	delimiter_position = ft_strchr(envp, c);
	if (!delimiter_position)
		return (NULL);
	keysize = delimiter_position - envp;
	key = malloc(sizeof(char) * (keysize + 1));
	if (!key)
		return (ft_putstr_fd("Internal error\n", 2), NULL);
	ft_strlcpy(key, envp, keysize + 1);
	value = ft_strdup(delimiter_position + 1);
	if (!value)
		return (ft_putstr_fd("Internal error\n", 2), free(key), NULL);
	splitted = malloc(sizeof(char *) * 3);
	if (!splitted)
		return (ft_putstr_fd("Internal error\n", 2),
			free(key), free(value), NULL);
	splitted[0] = key;
	splitted[1] = value;
	splitted[2] = NULL;
	return (splitted);
}

t_envp	*new_node(char *key, char *value)
{
	t_envp	*newnode;

	newnode = malloc(sizeof(t_envp));
	if (!newnode)
		return (NULL);
	newnode->key = ft_strdup(key);
	newnode->value = ft_strdup(value);
	newnode->next = NULL;
	return (newnode);
}

void	addnode_front(t_envp *node, t_envp **envp)
{
	node->next = *envp;
	*envp = node;
}

int	envsize(t_envp *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

bool	is_valid_key(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (false);
	while (key[i] && key[i] != '=')
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
