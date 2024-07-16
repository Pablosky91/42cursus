/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/16 17:42:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: check leaks

#include "push_swap.h"

static void		free_data(t_data *data);
static void		error(t_data *data);

//TODO delete
void	show_stacks(t_data *data)
{
	t_stack	*aux_a = data->top_a;
	t_stack	*aux_b = data->top_b;

	ft_printf("╭───────╥───────╮\n│   a\t║   b\t│\n╞═══════╬═══════╡\n");
	while (aux_a || aux_b)
	{
		if (aux_a)
		{
			ft_printf("│ %i\t║", aux_a->index);
			aux_a = aux_a->next;
		}
		else
			ft_printf("│\t║");
		if (aux_b)
		{
			ft_printf(" %i\t│\n", aux_b->index);
			aux_b = aux_b->next;
		}
		else
			ft_printf("\t│\n");
	}
	ft_printf("╰───────╨───────╯\n");
}

int	main(int argc, char **argv)
{
	t_data	*data = malloc(sizeof(t_data));
	
	data->top_a = 0;
	data->bot_a = 0;
	data->top_b = 0;
	data->bot_b = 0;
	data->size_a = 0;
	if (!read_data(data, argc, argv))
		error(data);




	//show_stacks(data);
	sort(data);
	//show_stacks(data);



	free_data(data);
	return (0);
}


static void	free_data(t_data *data)
{
	t_stack	*aux;
	t_stack	*copy;

	aux = data->top_a;
	while (aux)
	{
		copy = aux;
		aux = aux->next;
		free(copy);
	}
	free(data);
}

static void	error(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
