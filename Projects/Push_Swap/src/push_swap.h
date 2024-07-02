/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:35:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/02 17:41:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				content;
	unsigned int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//TODO same names as locations
typedef struct s_data
{
	t_stack			*top_a;
	t_stack			*bot_a;
	t_stack			*top_b;
	t_stack			*bot_b;
	unsigned int	size_a;
	unsigned int	size_b;
}	t_data;

typedef enum e_location
{
	top_a = 0,
	bot_a = 1,
	top_b = 2,
	bot_b = 3
}	t_location;

typedef struct s_half
{
	t_location			location;
	unsigned int		size;
	unsigned int		min_num;
	unsigned int		mid_num;
	unsigned int		max_num;
	struct s_half		*min_half;
	struct s_half		*max_half;
}	t_half;

typedef enum e_move
{
	no = 0,
	sa = 1,
	sb = 2,
	ss = 3,
	pa = 4,
	pb = 5,
	ra = 6,
	rb = 7,
	rr = 8,
	rra = 9,
	rrb = 10,
	rrr = 11
}	t_move;

//TODO delete
void	show_stacks(t_data *data);

void	moves(t_data *data, t_move move);
bool	read_data(t_data *data, int argc, char **argv);
void	sort(t_data *data);

#endif