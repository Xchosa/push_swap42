/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/13 09:50:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// if stack is bigger than 5 , sorting and push lowest Nr on top, than the next 
// to top of b . Highest Nr on top of stack b. 
// stack a (last 3 ) sortet 
void	chose_sorting(t_stack **a, t_stack **b)
{
	if (lstsize_ps(*a) <= 5)
	{
		if (lstsize_ps(*a) == 2)
			sort_two(a);
		if (lstsize_ps(*a) == 3)
			sort_three(a);
		if (lstsize_ps(*a) == 4)
			sort_four(a, b);
		if (lstsize_ps(*a) == 5)
			sort_five(a, b);
		return ;
	}
	else
	{
		turkswapsorting(a, b);
	}
}

/*
sort to stack B. Higgehst Nr on top.
pushing first two nbr to stack b
giving both stacks an index and group each ofthem in above median and below
calculate a targetnode for each nbr of stack a in stack b. 
identify the cheapest nbr, which has the fewest steps 
bring to it's targetnode.
calculate the shortest step to bring the cheapest node to the top 
(pushcost of cheapestnode)
and calculate seperately the steps to bring targetnode of b to top of stack
rotate and push
giving index and median again and repeat
*/
void	turkswapsorting(t_stack **a, t_stack **b)
{
	t_stack	*cheapestnode_a;

	ft_push_pb(a, b);
	ft_push_pb(a, b);
	sort_2_descending(b);
	while (lstsize_ps(*a) > 3)
	{
		give_index_and_median(a);
		give_index_and_median(b);
		target_of_a_in_stack_b(a, b);
		calc_push_cost_in_a(*a, *b);
		cheapestnode_a = find_a_node_for_cheapest_move(a);
		cost_to_move_node_to_top(*a, *b, cheapestnode_a);
		chose_rotate_command(a, b, cheapestnode_a);
	}
	sort_three(a);
	while (lstsize_ps(*b) >= 1)
	{
		give_index_and_median(a);
		give_index_and_median(b);
		target_of_b_in_stack_a(a, b);
		moving_b_node_to_target_b(a, b);
		ft_push_pa(a, b);
	}
	rotate_until_min_on_top(a);
}
