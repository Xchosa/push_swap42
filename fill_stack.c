/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:41:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 16:22:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// void put_index(t_stack *data)
// {
// 	data->index++;
// 	// bubbelsort nach kleinster nummer 
// 	// 
// 	// einen Loop kleinste 
// 	// bubbelsort 
// }

void print_content(t_stack *data)
{
	ft_printf("data: %d | index:  %d\n", data->data, data->index);
}

void give_index(t_stack **stack)
{
	int i;
	int median;

	i = 0;
	if(stack == NULL )
		return;
	median = lstsize_ps(*stack) / 2;
	while((*stack)->next != NULL)
	{
		(*stack)->index = i;
		if(i <= median)
			(*stack)->above_median = true;
		else
			(*stack)->above_median = false;
		stack = (*stack)->next;
		i++;
	}
}

void set_target(t_stack **a, t_stack **b)
{
	t_stack *current_node_b;
	t_stack *target_node;
	long	cheapest_index;
	while((*a)->next != NULL)
	{
		cheapest_index = LONG_MIN;
		current_node_b = b;
		while(current_node_b ->next != NULL)
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
		a  = (*a)->next;
	}
}
void calculate_cost(t_stack **a, t_stack **b)
{
	int stack_size_a;
	int stack_size_b;
	
	stack_size_a = lstsize_ps(*a);
	stack_size_b = lstsize_ps(*b);
	while ((*a)->next != NULL)
	{
		(*a)->push_cost = (*a)->index;
		if (!(*a)->above_median)
			(*a)->push_cost = stack_size_a - (*a)->index;
		if ((*a)->target->above_median)
			(*a)->push_cost = (*a)->push_cost + (*a)->target->index;
		else
			(*a)->push_cost = (*a)->push_cost + stack_size_b - (*a)->target->index;
		a  = (*a)->next;
	}
}

void find_cheapest_node(t_stack **stack)
{
	long	cheapest_data;
	t_stack	*cheapest_node;
	cheapest_data = LONG_MAX;
	
	while ((*stack)->next != NULL)
	{
		if((*stack)->push_cost < cheapest_data)
		{
			cheapest_data = (*stack)->push_cost;
			cheapest_node = stack;
		}
		stack = (*stack)->next;
	}
	cheapest_node->cheapest = true;
	
}

void fill_nodes(t_stack **a, t_stack **b)
{
	give_index(a);
	give_index(b);
	set_target(a, b);
	calculate_cost(a,b);
	set_cheapest(a);
}