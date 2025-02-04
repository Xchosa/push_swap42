/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_and_moving.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/04 14:01:26 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// choose function either to rotate or rev rotate or mixed
void	chose_rotate_command(t_stack **a, t_stack **b, t_stack *cheap_a)
{
	if (cheap_a->above_median && cheap_a->target->above_median)
		move_cheap_to_top_above_median(a, b, cheap_a);
	else if (!(cheap_a->above_median) && !(cheap_a->target->above_median))
		move_cheap_to_top_below_median(a, b, cheap_a);
	else if ((cheap_a->above_median) && !(cheap_a->target->above_median))
		move_cheap_above_and_below(a, b, cheap_a);
	else if (!(cheap_a->above_median) && (cheap_a->target->above_median))
		move_cheap_below_and_above(a, b, cheap_a);
	ft_push_pb(a, b);
}

// rotate a and b to top
// steps onl for a and steps only for b needed 

// both above median
void	move_cheap_to_top_above_median(t_stack **a, t_stack **b, t_stack *cp_a)
{
	int	pushcost_a;
	int	pushcost_b;

	pushcost_a = cp_a->push_cost;
	pushcost_b = cp_a->target->push_cost;
	while (pushcost_a != 0 && pushcost_b != 0)
	{
		ft_rotate_rr(a, b);
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
void	move_cheap_to_top_below_median(t_stack **a, t_stack **b, t_stack *cp_a)
{
	int	pushcost_a;
	int	pushcost_b;

	pushcost_a = cp_a->push_cost;
	pushcost_b = cp_a->target->push_cost;
	while (pushcost_a != 0 && pushcost_b != 0)
	{
		ft_rotate_rrr(a, b);
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
void	move_cheap_below_and_above(t_stack **a, t_stack **b, t_stack *cp_a)
{
	int	pushcost_a;
	int	pushcost_b;

	pushcost_a = cp_a->push_cost;
	pushcost_b = cp_a->target->push_cost;
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
void	move_cheap_above_and_below(t_stack **a, t_stack **b, t_stack *cp_a )
{
	int	pushcost_a;
	int	pushcost_b;

	pushcost_a = cp_a->push_cost;
	pushcost_b = cp_a->target->push_cost;
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
