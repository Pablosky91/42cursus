/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:48:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/06/18 19:21:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ps_new(int content);
static bool		ps_add_back(t_stack **lst, int content);
static bool		better_atoi(char *str, int *num);

bool	read_data(t_stack **stack, int argc, char **argv)
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
				return (free(split[j]), free(split), false);
			if (!ps_add_back(stack, num))
				return (free(split[j]), free(split), false);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (true);
}

static bool	better_atoi(char *str, int *num)
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
			return (false);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		result = result * 10 + str[i++] - '0';
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		return (false);
	*num = result * sign;
	return (true);
}

static t_stack	*ps_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = content;
	node->index = 0;
	node->next = 0;
	return (node);
}

//TODO maybe if !lst, lst = 0
static bool	ps_add_back(t_stack **lst, int content)
{
	t_stack	*aux;
	t_stack	*prev;
	t_stack	*new_node;

	if (!lst)
		return (false);
	new_node = ps_new(content);
	if (!new_node)
		return (false);
	if (!*lst)
		return (*lst = new_node, true);
	aux = *lst;
	while (aux)
	{
		if (aux->content < content)
			new_node->index++;
		else if (aux->content > content)
			aux->index++;
		else
			return (free(new_node), false);
		prev = aux;
		aux = aux->next;
	}
	prev->next = new_node;
	return (true);
}

// 6 4 2 3 5 1