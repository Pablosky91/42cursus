#include "minishell.h"

static int	lstlen(t_envp *lst);
static char	*create_line(char *s1, char *s2, char *s3);

char	**env_to_char(t_envp *env_lst)
{
	char	**envp;
	int		i;

	i = 0;
	envp = malloc((lstlen(env_lst) + 1) * sizeof(t_envp));
	if (!envp)
		return (ft_putstr_fd("Internal error\n", 2), NULL);
	while (env_lst)
	{
		envp[i] = create_line(env_lst->key, "=", env_lst->value);
		if (!envp[i])
			return (ft_free_double_pointer((void **)envp), NULL);
		env_lst = env_lst->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

static int	lstlen(t_envp *lst)
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

static char	*create_line(char *s1, char *s2, char *s3)
{
	char	*aux;
	char	*line;

	aux = ft_strjoin(s1, s2);
	if (!aux)
		return (ft_putstr_fd("Internal error\n", 2), NULL);
	line = ft_strjoin(aux, s3);
	free(aux);
	if (!line)
		return (ft_putstr_fd("Internal error\n", 2), NULL);
	return (line);
}
