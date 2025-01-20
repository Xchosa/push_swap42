/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/20 16:41:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


bool check_order(t_stack **a)
{
	t_stack *current_nbr;
	
	current_nbr = *a;
	
	while(current_nbr->next != NULL)
	{
		if(current_nbr->next->data < current_nbr ->data)
			return(false);
		current_nbr  = current_nbr->next;
	}
	return(true);
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
// cloest smaler number is re
// t_stack *cheapest_node_reachable(t_stack **stack)
// {
// 	t_stack cheapest;
// 	// operations to bring a on top
// 	//operations to bring a->target node on top = push cost

// 	if(a->data <  b->data)
// 		ft_push_a(&a);
// }

void sort(t_stack **a, t_stack **b)
{
	int a_nbr;
	int b_nbr;
	
	a_nbr = lstsize_ps(*a);
	
	while(a_nbr >3 && !check_order(&a))
	{
		sort_three(*a);
	}
	
}

void	sort_three(t_stack **stack)
{
	t_stack *head;
	t_stack *secondnode;
	t_stack *lastnode;

	head = *stack;
	secondnode = head->next;
	lastnode = lstlast_ps(*stack);
	if(check_order(stack))
		return;
	else if(secondnode->data < head->data && head->data < lastnode->data )
		ft_swap_sb(stack);
	else if(secondnode->data < head->data && secondnode->data < lastnode->data )
		ft_rotate_ra(stack);			
	else if(secondnode->data < head->data && secondnode->data > lastnode->data)
	{
		ft_rotate_ra(stack);
		ft_swap_sa(stack);
	}
	else if(lastnode->data < head->data && head->data < secondnode->data)
		ft_rotate_rra(stack);
	else if(head->data < lastnode->data && lastnode->data < secondnode->data)
	{
		ft_rotate_rra(stack);
		ft_swap_sa(stack);
	}
}
