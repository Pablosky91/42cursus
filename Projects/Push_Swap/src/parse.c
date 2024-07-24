/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:48:53 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 16:43:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ps_new(int content);
static t_error		ps_add_back(t_data *data, int content);
static t_error		better_atoi(char *str, int *num);

/*
Parses the arguments of the program to be nodes of a double linked list.
Returns false if it encounters any error
*/
t_error	read_data(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**split;
	t_error	error_code;

	i = 1;
	while (i < argc)
	{
		split = ((j = 0), ft_split(argv[i], ' '));
		if (!split[0])
			return (free(split), malloc_error);
		while (split[j])
		{
			if ((error_code = better_atoi(split[j], &num)))
				return (free(split[j]), free(split), error_code);
			if ((error_code = ps_add_back(data, num)))
				return (free(split[j]), free(split), error_code);
			data->size_a++;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (success);
}

/*
Saves the integer value of the given string to the given integer.
Returns false if it encounters any error.
*/
static t_error	better_atoi(char *str, int *num)
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
			return (not_an_integer);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (not_an_integer);
		result = result * 10 + str[i++] - '0';
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		return (not_range_integer);
	*num = result * sign;
	return (success);
}

/*
Creates and returns a new node.
*/
static t_node	*ps_new(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->content = content;
	node->index = 0;
	node->next = 0;
	node->prev = 0;
	return (node);
}

/*
Adds a new node with the given content.
Returns false if there is already a node with the given content.
*/
static t_error	ps_add_back(t_data *data, int content)
{
	t_node	*aux;
	t_node	*prev;
	t_node	*new_node;

	new_node = ps_new(content);
	if (!new_node)
		return (malloc_error);
	if (!data->top_a)
		return (data->top_a = new_node, data->bot_a = new_node, success);
	aux = ((prev = 0), data->top_a);
	while (aux)
	{
		if (aux->content < content)
			new_node->index++;
		else if (aux->content > content)
			aux->index++;
		else
			return (free(new_node), duplicate_number);
		prev = aux;
		aux = aux->next;
	}
	prev->next = new_node;
	new_node->prev = prev;
	data->bot_a = new_node;
	return (success);
}
