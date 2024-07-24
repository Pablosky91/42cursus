/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:35:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 19:07:03 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	//INCLUDE LIBRARIES//

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

	//ENUMS//

/*
Each of the possible error codes.
*/
typedef enum e_error
{
	success = 0,
	malloc_error = 1,
	duplicate_number = 2,
	not_an_integer = 3,
	not_range_integer = 4
}	t_error;

/*
Each of the possible locations of the stacks.
They are top and bottom for stacks a and b.
*/
typedef enum e_location
{
	top_a = 0,
	bot_a = 1,
	top_b = 2,
	bot_b = 3
}	t_location;

/*
Each of the possible moves.
NULL move is "no".
*/
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

	//STRUCTS//

/*
Node of the stack of numbers.
Contains the number provided by the user and the index of its final position.
Points to the next and previous nodes.
*/
typedef struct s_node
{
	int				content;
	unsigned int	index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*
Node of a list of instructions.
Contains the type of move and the consecutive quantity there are.
*/
typedef struct s_move_list
{
	t_move				move;
	int					quantity;
	struct s_move_list	*next;
	struct s_move_list	*prev;
}	t_move_list;

/*
Chunk of a stack to be divided and sorted.
Contains its location and size, as well as its minimum and maximum numbers.
It also contains a reference to two new halfs,
	one for the lower numbers and the other for the higher ones.
*/
typedef struct s_half
{
	t_location		location;
	unsigned int	size;
	unsigned int	min_num;
	unsigned int	max_num;
	struct s_half	*min_half;
	struct s_half	*max_half;
}	t_half;

/*
The data for all the program.
Contains the first and last node of each stack, as well as their size.
It also contains the first and last instruction of he solution.
*/
typedef struct s_data
{
	t_node			*top_a;
	t_node			*bot_a;
	t_node			*top_b;
	t_node			*bot_b;
	unsigned int	size_a;
	unsigned int	size_b;
	t_move_list		*move_list_first;
	t_move_list		*move_list_last;
}	t_data;

	//FUNCTIONS//

//TODO delete
void			show_stacks(t_data *data);

	//ALGORITHM.C//

t_error			sort(t_data *data);
t_error			move(t_data *data, t_move move);
t_error			move_from_to(t_data *data, t_location from, bool is_min);

	//BASE_CASES.C//

t_error			base_case_two(t_data *data, t_half *half, t_move *aux);
t_error			base_case_three(t_data *data, t_half *half);

	//CUT_MOVES.C//

void			cut_moves(t_data *data);

	//EXECUTE_MOVE.C//

void			execute_move(t_data *data, t_move move);

	//GET_NODE.C//

t_node			*get_first_node(t_data *data, t_half *half);
bool			node_forward(t_node **node, t_data *data, t_half *half);
bool			node_backward(t_node **node, t_half *half);

	//INSTRUCTIONS.C//

t_error			save_move(t_data *data, t_move move);
void			print_moves(t_data *data);

	//PARSE.C//

t_error			read_data(t_data *data, int argc, char **argv);

	//PUSH_SWAP.C//

void			error(t_data *data, t_error error);

	//SIMPLIFY.C//

void			bottom_to_top(t_data *data, t_half *half);
t_error			simplify_max(t_data *data, t_half *half);
t_error	simplify_min_before(t_data *data, t_half *half, unsigned int *n_mins);
t_error			simplify_min_after(t_data *data, t_half *half,
					unsigned int n_mins);

	//SORT_FEW.C//

t_error			sort_two(t_data *data);
t_error			sort_three(t_data *data);

#endif