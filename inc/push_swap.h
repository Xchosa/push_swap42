/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/22 16:39:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

// exclude later
#include <stdio.h>

typedef struct s_stack
{
	// bool		is_a;
	int			data;
	int			index;
	int			push_cost;
	bool		above_median;
	bool		cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;


// parse_nbr
int		start_parse(int argc, char **argv, t_stack**a);
int		parse_input(char **data, t_stack **a);
int 	parse_data_multiple_arg(char **argv, t_stack **a );
int		check_duplicates(t_stack **stack);

// fill_stack
void 	give_index(t_stack **data);
void	print_content(t_stack *data);

// sorting
void	sort(t_stack **a, t_stack **b);
bool	check_order(t_stack **a);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_5(t_stack **a, t_stack **b);

//Sort Algo (in fill.stack)
void	sorting_more(t_stack **a, t_stack **b);
void	fill_nodes_a(t_stack **a, t_stack **b);
void	fill_nodes_b(t_stack **a, t_stack **b);
t_stack *get_max_nbr_totalstack(t_stack **stack);
t_stack *get_min_nbr_totalstack(t_stack **stack);
void	set_target(t_stack **a, t_stack **b);
void	find_cheapest_node(t_stack **stack);
void	set_target(t_stack **a, t_stack **b);
void	set_target_biggest_nbr(t_stack **a, t_stack **b);
void 	calculate_cost(t_stack **a, t_stack **b);
t_stack	*pointer_to_cheapest_node(t_stack **stack);
void	a_stack_to_b_stack (t_stack **a, t_stack **b);
void	b_stack_to_a_stack(t_stack **a, t_stack **b);
void	smallest_on_top_a(t_stack **a);

void	rev_rotate_a_b_to_top(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate_a_b_to_top(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate_a_until_cheapest_on_top(t_stack **a, t_stack *cheapest_node);
void	rotate_b_until_cheapest_on_top(t_stack **b, t_stack *cheapest_node);


// list_push_swap
void	lstadd_back_ps(t_stack **lst, t_stack *new);
void	lstadd_front_ps(t_stack **lst, t_stack *new);
void	lstiter_ps(t_stack *lst, void (*f)(t_stack *));
void	lstclear_ps(t_stack **lst, void (*del)(void *));
t_stack	*lstlast_ps(t_stack *lst);
t_stack	*lstnew_ps(int content);
int		lstsize_ps(t_stack *lst);

// void	ft_swap_2nbr(t_stack**a);
// void	ft_swap_only(t_stack **a);


void	ft_swap_sb(t_stack **b);
void	ft_swap_sa(t_stack **a);
void	ft_swap_ss(t_stack **a, t_stack **b);


void	ft_push_pb(t_stack **b, t_stack **a);
void	ft_push_pa(t_stack **a, t_stack **b);

void	ft_rotate_ra (t_stack **a);
void	ft_rotate_rb (t_stack **b);
void	ft_rotate_rr(t_stack **a, t_stack **b);
void	ft_rotate_rra(t_stack **a);
void	ft_rotate_rrb(t_stack **b);
void	ft_rotate_rrr(t_stack **a, t_stack **b);
// void	del(void *data);




#endif