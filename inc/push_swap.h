/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/18 09:49:17 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// parse_nbr
int		start_parse(int argc, char **argv, t_stack**a);
int		parse_input(char **data, t_stack **a);
int		parse_data_multiple_arg(char **argv, t_stack **a );
int		check_duplicates(t_stack **stack);
void	free_string(char **str);

// fill_stack
void	give_index_and_median(t_stack **stack);
void	print_content(t_stack *data);
// sorting small 
bool	check_order(t_stack **a);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
// sort Algo
void	chose_sorting(t_stack **a, t_stack **b);
void	turkswapsorting(t_stack **a, t_stack **b);
void	sort_2_descending(t_stack **b);
void	target_of_a_in_stack_b(t_stack **a, t_stack **b);
void	calc_push_cost_in_a(t_stack *a, t_stack *b);
void	save_lines_calc_push_cost(t_stack *a, int push_cost_a, int push_cost_b);
t_stack	*find_a_node_for_cheapest_move(t_stack **a);
void	cost_to_move_node_to_top(t_stack *a, t_stack *b, t_stack *cheap_a);

//Algo moving stack
void	chose_rotate_command(t_stack **a, t_stack **b, t_stack *cp_a);
void	move_cheap_to_top_above_median(t_stack **a, t_stack **b, t_stack *cp_a);
void	move_cheap_to_top_below_median(t_stack **a, t_stack **b, t_stack *cp_a);
void	move_cheap_below_and_above(t_stack **a, t_stack **b, t_stack *cp_a);
void	move_cheap_above_and_below(t_stack **a, t_stack **b, t_stack *cp_a);
void	rotate_until_max_on_top(t_stack **b);
void	free_stack(t_stack **stack);
// moving sorted stack b back to a
void	target_of_b_in_stack_a(t_stack **a, t_stack **b);
void	moving_b_node_to_target_b(t_stack **a, t_stack **b);
void	rotate_until_min_on_top(t_stack **a);
//
//testing
// void	print_content_targetnode(t_stack *data);
// void	print_content_above_median(t_stack *data);
// void	print_content_targetnode_cheapest (t_stack *data);
// void	print_content_plain(t_stack *data);
// void	print_content_above_median_for_b(t_stack *data);
//
t_stack	*get_max_nbr_totalstack(t_stack **stack);
t_stack	*get_min_nbr_totalstack(t_stack **stack);
void	smallest_on_top_a(t_stack **a);
//
// list_push_swap
void	lstadd_back_ps(t_stack **lst, t_stack *new);
void	lstadd_front_ps(t_stack **lst, t_stack *new);
void	lstiter_ps(t_stack *lst, void (*f)(t_stack *));
void	lstclear_ps(t_stack **lst, void (*del)(void *));
t_stack	*lstlast_ps(t_stack *lst);
t_stack	*lstnew_ps(int content);
int		lstsize_ps(t_stack *lst);
//	moving stack a and b
void	ft_swap_sb(t_stack **b);
void	ft_swap_sa(t_stack **a);
void	ft_swap_ss(t_stack **a, t_stack **b);
void	ft_push_pb(t_stack **b, t_stack **a);
void	ft_push_pa(t_stack **a, t_stack **b);
void	ft_rotate_ra(t_stack **a);
void	ft_rotate_rb(t_stack **b);
void	ft_rotate_rr(t_stack **a, t_stack **b);
void	ft_rotate_rra(t_stack **a);
void	ft_rotate_rrb(t_stack **b);
void	ft_rotate_rrr(t_stack **a, t_stack **b);
// checker
void	read_commands(t_stack **a, t_stack **b);
void	read_and_use_commands(char *command, t_stack **a, t_stack **b);
void	ft_swap_sb_b(t_stack **b);
void	ft_swap_sa_b(t_stack **a);
void	ft_swap_ss_b(t_stack **a, t_stack **b);
void	ft_push_pb_b(t_stack **b, t_stack **a);
void	ft_push_pa_b(t_stack **a, t_stack **b);
void	ft_rotate_ra_b(t_stack **a);
void	ft_rotate_rb_b(t_stack **b);
void	ft_rotate_rr_b(t_stack **a, t_stack **b);
void	ft_rotate_rra_b(t_stack **a);
void	ft_rotate_rrb_b(t_stack **b);
void	ft_rotate_rrr_b(t_stack **a, t_stack **b);
#endif