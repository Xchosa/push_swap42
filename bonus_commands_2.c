/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:38:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/11 16:39:14 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	ft_rotate_rra_b(t_stack **a)
{
	t_stack	*head;
	t_stack	*lastnode;
	t_stack	*second_last;

	if ((*a == NULL) || ((*a)->next == NULL))
		return ;
	head = *a;
	lastnode = lstlast_ps(*a);
	second_last = *a;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	lastnode->next = head;
	*a = lastnode;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_rotate_rrb_b(t_stack **b)
{
	t_stack	*head;
	t_stack	*lastnode;
	t_stack	*second_last;

	if ((*b == NULL ) || ((*b)->next == NULL))
		return ;
	head = *b;
	lastnode = lstlast_ps(*b);
	second_last = *b;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	lastnode->next = head;
	*b = lastnode;
}

// rrr : rra and rrb at the same time.
void	ft_rotate_rrr_b(t_stack **a, t_stack **b)
{
	t_stack	*head;
	t_stack	*lastnode;
	t_stack	*second_last;

	if ((*b == NULL ) || ((*b)->next == NULL))
		return ;
	head = *b;
	lastnode = lstlast_ps(*b);
	second_last = *b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next = NULL;
	lastnode->next = head;
	*b = lastnode;
	head = *a;
	lastnode = lstlast_ps(*a);
	second_last = *a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next = NULL;
	lastnode->next = head;
	*a = lastnode;
}
