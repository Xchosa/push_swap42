/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/22 16:45:23 by poverbec         ###   ########.fr       */
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

void sort_5(t_stack **a, t_stack **b)
{
	give_index(a);
	smallest_on_top_a(a);// fill median 
	// calculate_cost(t_stack **a, t_stack **b)
	ft_push_pa(a, b);
}
