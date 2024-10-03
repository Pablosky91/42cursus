/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:48:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 09:41:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool		better_atoi(t_data *data, char *str, int *num);
static t_node	*ps_new(int content);
static bool		ps_add_back(t_data *data, int content);

/*
Parses the arguments of the program to be nodes of a double linked list.
Returns false if it encounters any error.
*/
bool	read_data(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i++], ' ');
		if (!split || !split[0])
			return (free(split), provoke_error(data, MALLOC_ERROR));
		while (split[j])
		{
			if (!better_atoi(data, split[j], &num))
				return (ft_free_double_pointer((void **)split));
			if (!ps_add_back(data, num))
				return (ft_free_double_pointer((void **)split));
			data->size_a++;
			j++;
		}
		ft_free_double_pointer((void **)split);
	}
	return (!data->error_code);
}

/*
Saves the integer value of the given string to the given integer.
Returns false if it encounters any error.
*/
static bool	better_atoi(t_data *data, char *str, int *num)
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
			return (provoke_error(data, NOT_AN_INTEGER));
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (provoke_error(data, NOT_AN_INTEGER));
		result = result * 10 + str[i++] - '0';
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (provoke_error(data, NOT_RANGE_INTEGER));
	}
	*num = result * sign;
	return (!data->error_code);
}

/*
Creates and returns a new node.
*/
static t_node	*ps_new(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*
Adds a new node with the given content.
Returns false if it encounters any error.
*/
static bool	ps_add_back(t_data *data, int content)
{
	t_node	*iter;
	t_node	*prev;
	t_node	*new_node;

	new_node = ps_new(content);
	if (!new_node)
		return (provoke_error(data, MALLOC_ERROR));
	if (!data->top_a)
		return (data->top_a = new_node, data->bot_a = new_node, true);
	iter = data->top_a;
	while (iter)
	{
		if (iter->content < content)
			new_node->index++;
		else if (iter->content > content)
			iter->index++;
		else
			return (free(new_node), provoke_error(data, DUPLICATE_NUMBER));
		prev = iter;
		iter = iter->next;
	}
	prev->next = new_node;
	new_node->prev = prev;
	data->bot_a = new_node;
	return (!data->error_code);
}
