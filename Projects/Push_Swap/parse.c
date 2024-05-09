/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:48:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/09 20:08:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_new(int content);
static int		ps_add_back(t_stack **lst, int content);
static int		better_atoi(char *str, int *num);

int	read_data(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!better_atoi(split[j], &num))
				return (free(split[j]), free(split), 0);
			if (!ps_add_back(stack, num))
				return (free(split[j]), free(split), 0);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (1);
}

static int	better_atoi(char *str, int *num)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		return (0);
	*num = result * sign;
	return (1);
}

static t_stack	*ps_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

//TODO maybe if !lst, lst = 0
static int	ps_add_back(t_stack **lst, int content)
{
	t_stack	*aux;
	t_stack	*new_node;

	if (!lst)
		return (0);
	new_node = ps_new(content);
	if (!new_node)
		return (0);
	aux = *lst;
	if (!*lst)
		*lst = new_node;
	else
	{
		while (aux->next)
		{
			if (aux->content == content)
				return (free(new_node), 0);
			aux = aux->next;
		}
		if (aux->content == content)
			return (free(new_node), 0);
		aux->next = new_node;
	}
	return (1);
}
