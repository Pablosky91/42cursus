/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:35:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/16 23:34:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

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

typedef enum e_location
{
	top_a = 0,
	bot_a = 1,
	top_b = 2,
	bot_b = 3
}	t_location;

typedef struct s_move_list
{
	t_move				move;
	unsigned int		quantity;
	struct s_move_list	*next;
	struct s_move_list	*prev;
}	t_move_list;

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
	t_move_list		*move_list_first;
	t_move_list		*move_list_last;
}	t_data;

typedef struct s_half
{
	t_location		location;
	unsigned int	size;
	unsigned int	min_num;
	unsigned int	max_num;
	struct s_half	*min_half;
	struct s_half	*max_half;
}	t_half;

//TODO delete
void	show_stacks(t_data *data);

void	move(t_data *data, t_move move);
bool	read_data(t_data *data, int argc, char **argv);
void	sort(t_data *data);
void	move_from_to(t_data *data, t_location from, bool is_min);

void	base_case_2(t_data *data, t_half *half);
void	base_case_3(t_data *data, t_half *half);

void	bottom_to_top(t_data *data, t_half *half);
void	simplify_max(t_data *data, t_half *half);
unsigned int	simplify_min(t_data *data, t_half *half);

t_stack	*get_first_stack(t_half *half, t_data *data);
bool	stack_forward(t_stack **stack, t_half *half, t_data *data);
bool	stack_backward(t_stack **stack, t_half *half);

void	save_move(t_data *data, t_move move);
void	print_moves(t_data *data);

#endif