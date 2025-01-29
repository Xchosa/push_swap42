/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_and_moving.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/29 15:19:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// choose function either to rotate or rev rotate or mixed
void chose_rotate_command(t_stack **a, t_stack **b, t_stack *cheapest_node_a)
{
	// ft_printf("---------Rotation------------------- \n\n");
	// ft_printf("\n cheapest node a  pushcost: %d |  Zahl : %d \n " ,cheapest_node_a->push_cost, cheapest_node_a->data);
	// ft_printf("\n cheapest node b   pushcost: %d |  Zahl : %d \n " ,cheapest_node_a->target->push_cost, cheapest_node_a->target->data);
	
	if(cheapest_node_a->above_median && cheapest_node_a->target->above_median)
		move_cheapest_to_top_above_median(a, b, cheapest_node_a);
	if(!(cheapest_node_a->above_median) && !(cheapest_node_a->target->above_median))
		move_cheapest_to_top_below_median(a, b, cheapest_node_a);
	if((cheapest_node_a->above_median) && !(cheapest_node_a->target->above_median))
		move_cheapest_to_top_above_and_below_median(a,b,cheapest_node_a );
	if(!(cheapest_node_a->above_median) && (cheapest_node_a->target->above_median))
		move_cheapest_to_top_below_and_above_median(a, b, cheapest_node_a);
	ft_push_pa(a,b);
	rotate_until_max_on_top(b);
}


void rotate_until_max_on_top(t_stack **b)
{
	t_stack *max_nbr;
	give_index_and_median(b);
	max_nbr = get_max_nbr_totalstack(b);
	if(!max_nbr->above_median)
	{
		while(max_nbr->index != 0)
		{
			ft_rotate_rrb(b);
			give_index_and_median(b);
		}
	}
	else
	{
		while(max_nbr->index != 0)
		{
			ft_rotate_rb(b);
			give_index_and_median(b);
		}
	}
}




// rotate a and b to top
// steps onl for a and steps only for b needed 

// both above median
void move_cheapest_to_top_above_median(t_stack **a, t_stack **b, t_stack *cheapest_node_a)
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
// both nodes below median , reverse rotate
void move_cheapest_to_top_below_median(t_stack **a, t_stack **b, t_stack *cheapest_node_a )
{
	int pushcost_a;
	int pushcost_b;
	pushcost_a = cheapest_node_a->push_cost;
	pushcost_b = cheapest_node_a->target->push_cost;
	while(pushcost_a != 0 && pushcost_b != 0)
	{
		ft_rotate_rrr(a,b);
		pushcost_a--;
		pushcost_b--;
	}
	while (pushcost_a != 0)
	{
		ft_rotate_rra(a);
		pushcost_a--;
	}
	while (pushcost_b != 0)
	{
		ft_rotate_rrb(b);
		pushcost_b--;
	}
}
// a node is below median , target node in b is above median
void	move_cheapest_to_top_below_and_above_median(t_stack **a, t_stack **b, t_stack *cheapest_node_a )
{
	int pushcost_a;
	int pushcost_b;
	
	pushcost_a = cheapest_node_a->push_cost;
	pushcost_b = cheapest_node_a->target->push_cost;
	while (pushcost_a != 0)
	{
		ft_rotate_rra(a);
		pushcost_a--;
	}
	while (pushcost_b != 0)
	{
		ft_rotate_rb(b);
		pushcost_b--;
	}
}
// a node is above median , target node in b is below median
void	move_cheapest_to_top_above_and_below_median(t_stack **a, t_stack **b, t_stack *cheapest_node_a )
{
	int pushcost_a;
	int pushcost_b;
	
	pushcost_a = cheapest_node_a->push_cost;
	pushcost_b = cheapest_node_a->target->push_cost;
	while (pushcost_a != 0)
	{
		ft_rotate_ra(a);
		pushcost_a--;
	}
	while (pushcost_b != 0)
	{
		ft_rotate_rrb(b);
		pushcost_b--;
	}
}