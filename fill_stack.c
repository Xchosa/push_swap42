/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:41:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/28 15:42:39 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// remember allways set stack back to head. 


// count through the stack. From 0 on. 
// give boolen value above median or below. 
// set stack back to head. 
void	give_index_and_median(t_stack **stack)
{
	int i;
	int median;
	t_stack *head;
	
	head = *stack;
	i = 0;
	if(stack == NULL || *stack == NULL)
		return;
	median = (lstsize_ps(*stack) / 2);
	while(*stack != NULL)
	{
		(*stack)->index = i;
		if(i < median)
			(*stack)->above_median = true;
		else
			(*stack)->above_median = false;
		stack = &((*stack)->next);
		i++;
	}
	stack = &head;
}

void	sort_2_descending(t_stack **b)
{
	if((*b)->data < (*b)->next->data)
		ft_rotate_rb(b);
	else
		return;
}

// find nbr with the closest Nr in a stack
// void	set_target(t_stack **a, t_stack **b)
// {
// 	t_stack *current_node_b;
// 	t_stack *target_node;
// 	long	cheapest_index;
// 	while((*a) != NULL)
// 	{
// 		cheapest_index = LONG_MIN;
// 		current_node_b = *b;
// 		while(current_node_b != NULL)
// 		{
// 			if ((current_node_b)->data < (*a)->data && current_node_b ->data > cheapest_index) 
// 			{
// 				cheapest_index = current_node_b ->data;
// 				target_node = current_node_b;
// 			}
// 			current_node_b= current_node_b->next;
// 		}
// 		if(cheapest_index == LONG_MIN)
// 			(*a)->target = get_max_nbr_totalstack(b);// set pointer target
// 		else
// 			(*a)->target = target_node;
// 		a  = &((*a)->next);
// 		printf("target_node %d", (*a)->data);
// 	}
// }





//find nbr with the fewest diff to the top node of b 
void set_target_in_a(t_stack **a, t_stack **b)
{
	t_stack *head;
	t_stack *target_node_a;
	int		smallest_differents;
	
	head = *a;
	
	
	smallest_differents = INT_MAX;
	target_node_a = NULL;
	while(a != NULL)		
	{
		if((*a)->data  > (*b)->data && ((*a)->data - (*b)->data < smallest_differents))
		{
			target_node_a = *a;
			smallest_differents = (*a)->data - (*b)->data;
		}
		a = &(*a)->next;
	}
	(*b)->target = target_node_a;
	if(target_node_a == NULL)
		(*b)->target= get_min_nbr_totalstack(a);
	a = &head;
}

// find biggest Nr in a

// calc the push cost for each node (in stack a)
void calculate_cost(t_stack **a, t_stack **b)
{
	int stack_size_a;
	int stack_size_b;
	
	stack_size_a = lstsize_ps(*a);
	stack_size_b = lstsize_ps(*b);
	while (*a != NULL)
	{
		(*a)->push_cost = (*a)->index;
		if (!(*a)->above_median)
			(*a)->push_cost = stack_size_a - (*a)->index;
		if ((*a)->target->above_median)
			(*a)->push_cost = (*a)->push_cost + (*a)->target->index;
		else
			(*a)->push_cost = (*a)->push_cost + stack_size_b - (*a)->target->index;
		a  = &((*a)->next);
	}
}

void	find_cheapest_node(t_stack **stack)
{
	long	cheapest_data;
	t_stack	*cheapest_node;
	cheapest_data = LONG_MAX;
	
	while ((*stack)->next != NULL)
	{
		if((*stack)->push_cost < cheapest_data)
		{
			cheapest_data = (*stack)->push_cost;
			cheapest_node = *stack;
		}
		stack = &((*stack)->next);
	}
	cheapest_node->cheapest = true;
	
}

// void fill_nodes_a(t_stack **a, t_stack **b)
// {
// 	give_index(a);
// 	give_index(b);
// 	set_target_in_a(a, b);
	
// 	calculate_cost(a,b);
// 	find_cheapest_node(a);
// }

// void fill_nodes_b(t_stack **a, t_stack **b)
// {
// 	give_index(a);
// 	give_index(b);
// 	set_target(a,b);
// }