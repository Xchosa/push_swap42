/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:16:19 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/30 11:48:08 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


bool check_order(t_stack **stack)
{
	t_stack *current_nbr;
	
	current_nbr = *stack;
	
	while(current_nbr->next != NULL)
	{
		if(current_nbr->next->data < current_nbr ->data)
			return(false);
		current_nbr  = current_nbr->next;
	}
	return(true);
}
void	give_index_and_median(t_stack **stack)
{
	int i;
	int median;
	t_stack *current;
	
	current = *stack;
	i = 0;
	if(stack == NULL || *stack == NULL)
		return;
	median = (lstsize_ps(*stack) / 2);
	while(current != NULL)
	{
		(current)->index = i;
		if(i < median)
			(current)->above_median = true;
		else
			(current)->above_median = false;
		current = current->next;
		i++;
	}
	return;
}
//find max Number
// get pointer to Node with biggest Num of the total stack
t_stack *get_max_nbr_totalstack(t_stack **stack)
{
	t_stack *max_nbr;
	t_stack *current_nbr;
	
	current_nbr = *stack;
	max_nbr = *stack;
	
	while( current_nbr != NULL)
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
	
	while( current_nbr != NULL)
	{
		if(min_nbr->data > current_nbr->data)
			min_nbr = current_nbr;
		else
			current_nbr= current_nbr ->next;
	}
	return(min_nbr);
}
