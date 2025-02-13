/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/13 09:50:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// find target node for every a node in stack b
// target = closest smaller Num in stack b;
// if no smaller Num found , target node in a stack
// will be the biggest nbr in stack b
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
// only after giving each node in a its struct 
// int push_cost to move the node to top of stack

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
			save_lines_calc_push_cost(a, push_cost_a, push_cost_b);
		}
		else
			a->push_cost = push_cost_a + push_cost_b;
		a = a->next;
	}
}

void	save_lines_calc_push_cost(t_stack *a, int push_cost_a, int push_cost_b)
{
	if (push_cost_a > push_cost_b)
		a->push_cost = push_cost_a;
	else
		a->push_cost = push_cost_b;
}

// find cheapest node , the node in a with lowest push_cost 
// (given in calc_push_cost_in_a)
// set target_node in b stack on true // dont need it?
t_stack	*find_a_node_for_cheapest_move(t_stack **a)
{
	int		smallest_push_costs;
	t_stack	*current_a;
	t_stack	*cheapest_node;

	smallest_push_costs = INT_MAX;
	current_a = *a;
	while (current_a != NULL)
	{
		if (smallest_push_costs > current_a->push_cost)
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
void	cost_to_move_node_to_top(t_stack *a, t_stack *b, t_stack *cp_a)
{
	int	push_cost_a;
	int	push_cost_b;

	if (cp_a->above_median)
		push_cost_a = cp_a->index;
	if (!(cp_a->above_median))
		push_cost_a = (lstlast_ps(a)->index +1 - cp_a->index);
	if (cp_a->target->above_median)
		push_cost_b = cp_a->target->index;
	if (!(cp_a->target->above_median))
		push_cost_b = lstlast_ps(b)->index + 1 - cp_a->target->index;
	cp_a->push_cost = push_cost_a;
	cp_a->target->push_cost = push_cost_b;
}
