/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:16:19 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/22 16:34:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


void sorting_more(t_stack **a, t_stack **b)
{
	int size_stack;
	size_stack = lstsize_ps(*a);
	// better sortalgo for 5 and less 
	
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_pa(a, b);
		size_stack--;
	}
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_pa(a, b);
		size_stack--;
	}
	// while(size_stack > 3 && !check_order(a))
	// {
	// 	fill_nodes_a(a,b);
	// 	a_stack_to_b_stack(a,b);
	// 	size_stack--;
	// }
	// sort_three(a);

	
	// while(b != NULL)
	// {
	// 	fill_nodes_b(a, b);
	// 	b_stack_to_a_stack(a,b);
	// }
	// give_index(a);
	// smallest_on_top_a(a);
}
// operations to move the founded cheapest node of a to b;
// above median to rotate, under median to rev_rotate
void	a_stack_to_b_stack (t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;
	cheapest_node = pointer_to_cheapest_node(a);
	if((cheapest_node->above_median) && cheapest_node->target->above_median)
		rotate_a_b_to_top(a,b, cheapest_node);
	else if(!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rev_rotate_a_b_to_top(a, b, cheapest_node);
	rotate_a_until_cheapest_on_top(a, cheapest_node);
	rotate_b_until_cheapest_on_top(b, cheapest_node->target);
	ft_push_pa(a,b);
}

// make sure target not is on  top bevor pushing b to a
void	b_stack_to_a_stack(t_stack **a, t_stack **b)
{
	rotate_a_until_cheapest_on_top(a, (*b)->target);
	ft_push_pb(a,b);
}

void	rotate_a_until_cheapest_on_top(t_stack **a, t_stack *cheapest_node)
{
	while(*a != cheapest_node)
	{
		if(cheapest_node->above_median)
		{
			ft_rotate_ra(a);
			printf("line 77");
		}
		else
			ft_rotate_rra(a);
	}
}
void	rotate_b_until_cheapest_on_top(t_stack **b, t_stack *cheapest_node)
{
	while(*b != cheapest_node)
	{
		if(cheapest_node->above_median)
		{
			ft_rotate_rb(b);
			printf("line 87");
		}
		else
			ft_rotate_rrb(b);
	}
}
// rotate both stacks, for cheapest node on top
void rotate_a_b_to_top(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while(*b != cheapest_node->target && *a != cheapest_node)
		ft_rotate_rr(a, b);
	give_index(a);
	give_index(b);
}
void rev_rotate_a_b_to_top(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while(*b != cheapest_node->target && *a != cheapest_node)
		ft_rotate_rrr(a, b);
	give_index(a);
	give_index(b);
	smallest_on_top_a(a);
}
// find the boolean, value of the cheapest node 
t_stack	*pointer_to_cheapest_node(t_stack **stack)
{
	if(stack == NULL)
		return(NULL);
	while((*stack)->next != NULL)
	{
		if((*stack)->cheapest)
			return (*stack);
		(*stack) = (*stack)->next;
	}
	return (NULL);
}

void	 smallest_on_top_a(t_stack **a)
{
	while((*a)->data != get_min_nbr_totalstack(a)->data)
	{
		if(get_min_nbr_totalstack(a)->above_median)
			ft_rotate_ra(a);
		else
			ft_rotate_rra(a);
	}
}

//find max Number
t_stack *get_max_nbr_totalstack(t_stack **stack)
{
	t_stack *max_nbr;
	t_stack *current_nbr;
	
	current_nbr = *stack;
	max_nbr = *stack;
	
	while( stack != NULL)
	{
		if(max_nbr->data < current_nbr->data)
			max_nbr = current_nbr;
		else
			current_nbr= current_nbr ->next;
	}
	return(max_nbr);
}

//find smallest Number
t_stack *get_min_nbr_totalstack(t_stack **stack)
{
	t_stack *min_nbr;
	t_stack *current_nbr;
	
	current_nbr = *stack;
	min_nbr = *stack;
	
	while( stack != NULL)
	{
		if(min_nbr->data > current_nbr->data)
			min_nbr = current_nbr;
		else
			current_nbr= current_nbr ->next;
	}
	return(min_nbr);
}