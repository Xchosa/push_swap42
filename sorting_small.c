/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/03 16:00:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_2_descending(t_stack **b)
{
	if((*b)->data < (*b)->next->data)
		ft_rotate_rb(b);
	else
		return;
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
		ft_swap_sa(stack);
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

void sort_four(t_stack **a, t_stack **b)
{
	give_index_and_median(a);
	get_min_nbr_totalstack(a);
	smallest_on_top_a(a);
	ft_push_pb(a,b);
	sort_three(a);
	ft_push_pa(a,b);
	int i = 1;
	while(!check_order(a) && i < 5)
	{
		ft_rotate_ra (a);
		i++;
	}
}
void sort_five(t_stack **a, t_stack **b)
{
	smallest_on_top_a(a);
	ft_push_pb(a,b);
	sort_four(a,b);
	ft_push_pa(a,b);
}
