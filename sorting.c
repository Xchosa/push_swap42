/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 14:25:10 by poverbec         ###   ########.fr       */
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

void sort(t_stack **a, t_stack **b)
{
	int a_nbr;
	// int b_nbr;
	
	a_nbr = lstsize_ps(*a);
	
	while(a_nbr >3 && !check_order(a))
	{
		sort_three(a);
	}
	free(b);
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


void	sort_two(t_stack **stack)
{
	if(!check_order(stack))
		ft_swap_sa(stack);
	else
		lstiter_ps(*stack, print_content);
}


void sorting_more(t_stack **a, t_stack **b)
{
	int size_stack;
	t_stack *min_nbr;
	size_stack = lstsize_ps(a);
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_a(a, b);
		size_stack--;
	}
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_a(a, b);
		size_stack--;
	}
	while(size_stack > 3 && !check_order(a))
	{
		
		size_stack--;
	}
	ft_push_a(a, b);
	ft_push_a(a, b);
	sort_three(b); // 
	// min_nbr =  get_min_nbr_totalstack(t_stack )
	
}

void cheapest(t_stack **a, t_stack **b)
{
	
}