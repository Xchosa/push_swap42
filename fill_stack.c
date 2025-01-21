/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:41:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 15:14:41 by poverbec         ###   ########.fr       */
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


void fill_nodes(t_stack **a, t_stack **b)
{
	give_index(a);
	give_index(b);
	set_target(a, b);
}

// find closest smalest nbr
// void find_target_b(t_stack **a, t_stack **b)
// {
// 	t_stack *tmp;
// 	t_stack *closest;
// 	int		minimal_diff;
	
// 	while(*a != NULL)
// 	{
// 		closest = NULL;
// 		minimal_diff = INT_MAX;
// 		tmp = b;
// 		while(tmp != NULL)
// 		{
// 			if(tmp ->data < a->data && (a->data ))
// 		}
// 	}
// }