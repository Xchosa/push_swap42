/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_and_moving.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void chose_rotate_command(t_stack **a, t_stack **b, t_stack *cheapest_node_a)
{
	if(cheapest_node_a->above_median && cheapest_node_a->target->above_median)
		move_cheapest_to_top_above_median(a, b, cheapest_node_a);
	if(cheapest_node_a->above_median && !(cheapest_node_a->target->above_median))
		
	if(!(cheapest_node_a->above_median) && (cheapest_node_a->target->above_median))

	if(!(cheapest_node_a->above_median) && !(cheapest_node_a->target->above_median))
	
	
	ft_push_pa(a,b);
}

// rotate a and b to top
// steps onl for a and steps only for b needed 

// both above median
void move_cheapest_to_top_above_median(t_stack **a, t_stack **b, t_stack *cheapest_node_a )
{
	int pushcost_a;
	int pushcost_b;
	pushcost_a = cheapest_node_a->push_cost;
	pushcost_b = cheapest_node_a->target->push_cost;

	while(pushcost_a != 0 && pushcost_b != 0)
	{
		ft_rotate_rr(a,b);
		pushcost_a--;
		pushcost_b--;		
	}
	while (pushcost_a != 0)
	{
		ft_rotate_ra(a);
		pushcost_a--;
	}
	while (pushcost_b != 0)
	{
		ft_rotate_rb(b);
		pushcost_b--;
	}
}

