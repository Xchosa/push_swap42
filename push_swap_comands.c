/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:44:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/03 14:24:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


// turk sort ab bestimmter groeser, davor anderer sort
// am besten combinieren. 

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void ft_push_pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	if(*a == NULL)
		return;
	else
	{
		tmp = *b;
		*b = (*b)->next;
		lstadd_front_ps(a, tmp);
		ft_printf("pa\n");
	}
}
// pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void ft_push_pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	if(*a == NULL)
		return;
	else
	{
		tmp = *a;
		*a = (*a)->next;
		lstadd_front_ps(b, tmp);
		ft_printf("pb\n");
	}
}
//ra (rotate a): Shift up all elements of stack a by 1.
void	ft_rotate_ra (t_stack **a)
{
	t_stack	*head;
	t_stack	*last;

	head = *a;
	last = lstlast_ps(*a);

	ft_printf("ra\n");
	*a = head->next;
	last->next = head;
	head->next = NULL;	
}

//rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
void	ft_rotate_rb (t_stack **b)
{
	t_stack	*head;
	t_stack	*last;

	head = *b;
	last = lstlast_ps(*b);

	ft_printf("rb\n");
	*b = head->next;
	last->next = head;
	head->next = NULL;
}

//rr : ra and rb at the same time.
void	ft_rotate_rr(t_stack **a, t_stack **b)
{
	t_stack	*head;
	t_stack	*last;

	head = *a;
	last = lstlast_ps(*a);
	*a = head->next;
	last->next = head;
	head->next = NULL;

	head = *b;
	last = lstlast_ps(*b);
	*b = head->next;
	last->next = head;
	head->next = NULL;

	ft_printf("rr\n");
}

