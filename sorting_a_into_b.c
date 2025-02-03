/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/03 16:18:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

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

void	turkswapsorting(t_stack **a,t_stack **b)
{
	t_stack	*cheapestnode_a;

	ft_push_pb(a, b);
	ft_push_pb(a, b);
	sort_2_descending(b);
	while (lstsize_ps(*a) > 3 )
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

// ARG=" 9 8 7 6 5 4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG

// find target node for every a node in stack b
// target = closest smaller Num in stack b;
// if no smaller Num found , target node in a stack will be the biggest nbr in stack b
void	target_of_a_in_stack_b(t_stack **a, t_stack **b)
{
	int		smallest_differents;
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *a;
	while (current_a != NULL)
	{
		smallest_differents = INT_MAX;
		current_b = *b;
		while (current_b != NULL)
		{
			if ((current_a)->data > (current_b)->data)
			{
				if ((current_a)->data - (current_b)->data < smallest_differents)
				{
					smallest_differents = (current_a)->data - (current_b)->data;
					(current_a)->target = current_b;
				}
			}
			current_b = current_b->next;
		}
		if (smallest_differents == INT_MAX)
			(current_a)->target = get_max_nbr_totalstack(b);
		(current_a) = (current_a)->next;
	}
}
// calc push cost 
// only after giving each node in a its struct  int push_cost to move the node to top of stack

// moves to bring a on top
// + moves to bring a-targetnode on top (in stack b)
void	calc_push_cost_in_a(t_stack *a, t_stack *b)
{
	int	push_cost_a;
	int	push_cost_b;

	while (a != NULL)
	{
		push_cost_a = 0;
		push_cost_b = 0;
		if (a->above_median)
			push_cost_a = a->index;
		else if (!(a->above_median))
			push_cost_a = (lstlast_ps(a)->index - a->index);
		if (a->target->above_median)
			push_cost_b = a->target->index;
		else if (!(a->target->above_median))
			push_cost_b = (lstlast_ps(b)->index - a->target->index);
		if (a->above_median == a->target->above_median)
		{
			if (push_cost_a > push_cost_b)
				a->push_cost = push_cost_a;
			else
				a->push_cost = push_cost_b;	
		}
		else
			a->push_cost = push_cost_a + push_cost_b;
		a = a->next;
	}
}

// find cheapest node , the node in a with lowest push_cost (given in calc_push_cost_in_a)
// set target_node in b stack on true // dont need it?
t_stack *find_a_node_for_cheapest_move(t_stack **a)
{
	int smallest_push_costs;
	t_stack *current_a;
	t_stack *cheapest_node;
	smallest_push_costs = INT_MAX;
	current_a = *a;
	while(current_a != NULL)
	{
		if( smallest_push_costs > current_a->push_cost)
		{
			smallest_push_costs = current_a->push_cost;
			cheapest_node = NULL;
			cheapest_node = current_a;
		}
		else
			current_a = current_a->next;
	}
	return (cheapest_node);
}

// cheapest node in a is found, and has a target_node in b;
// cheapest node is the one needed with the fewest step to 
// move on top, and according to its target node;
// asign each node its own cost to move to top 
// cheapest_node in a to get moved to top and its targetnode 
// in b to get move to top
void cost_to_move_node_to_top(t_stack *a, t_stack *b, t_stack *cheapest_node_a)
{
	int push_cost_a;
	int push_cost_b;

	if (cheapest_node_a->above_median)
		push_cost_a = cheapest_node_a->index;
	if (!(cheapest_node_a->above_median))
		push_cost_a = (lstlast_ps(a)->index +1 - cheapest_node_a->index);
	if (cheapest_node_a->target->above_median)
		push_cost_b = cheapest_node_a->target->index;
	if (!(cheapest_node_a->target->above_median))
		push_cost_b = lstlast_ps(b)->index + 1 - cheapest_node_a->target->index;

	cheapest_node_a->push_cost = push_cost_a;
	cheapest_node_a->target->push_cost = push_cost_b;
}

