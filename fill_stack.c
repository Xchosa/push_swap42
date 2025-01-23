/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:41:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/23 16:27:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// remember allways set stack back to head. 

void	print_content(t_stack *data)
{
	ft_printf("data: %d | index:  %d " ,data->data, data->index);
	if (!(data->above_median))
		ft_printf("above_median false\n");
	else
		ft_printf("above_median true\n");
}

	


// count through the stack. From 0 on. 
// give boolen value above median or below. 
// set stack back to head. 
void	give_index(t_stack **stack)
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
		if(i <= median)
			(*stack)->above_median = false;
		else
			(*stack)->above_median = true;
		stack = &((*stack)->next);
		i++;
	}
	stack = &head;
}

//
void	set_target(t_stack **a, t_stack **b)
{
	t_stack *current_node_b;
	t_stack *target_node;
	long	cheapest_index;
	while((*a) != NULL)
	{
		cheapest_index = LONG_MIN;
		current_node_b = *b;
		while(current_node_b != NULL)
		{
			if ((current_node_b)->data < (*a)->data && current_node_b ->data > cheapest_index) 
			{
				cheapest_index = current_node_b ->data;
				target_node = current_node_b;
			}
			current_node_b= current_node_b->next;
		}
		if(cheapest_index == LONG_MIN)
			(*a)->target = get_max_nbr_totalstack(b);// set pointer target
		else
			(*a)->target = target_node;
		a  = &((*a)->next);
		printf("target_node %d", (*a)->data);
	}
}


// find biggest Nr in a
void	set_target_biggest_nbr(t_stack **a, t_stack **b)
{
	t_stack *current_node_a;
	t_stack *target_node;
	long	cheapest_index;
	while((*a)->next != NULL)
	{
		cheapest_index = LONG_MAX;
		current_node_a = *a;
		while(current_node_a->next != NULL)
		{
			if ((current_node_a)->data > (*b)->data && current_node_a ->data < cheapest_index) 
			{
				cheapest_index = current_node_a ->data;
				target_node = current_node_a;
			}
			current_node_a= current_node_a->next;
		}
		if(cheapest_index == LONG_MIN)
			(*b)->target = get_min_nbr_totalstack(a);// set pointer target
		else
			(*b)->target = target_node;
		b  = &((*b)->next);
	}
}
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

void fill_nodes_a(t_stack **a, t_stack **b)
{
	give_index(a);
	give_index(b);
	set_target(a, b);
	calculate_cost(a,b);
	find_cheapest_node(a);
}

void fill_nodes_b(t_stack **a, t_stack **b)
{
	give_index(a);
	give_index(b);
	set_target(a,b);
}