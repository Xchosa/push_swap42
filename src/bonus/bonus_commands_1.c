/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:36:29 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/13 09:41:42 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// pa (push a): Take the first element at the top of b 
// and put it at the top of a.
//Do nothing if b is empty.
void	ft_push_pa_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	else
	{
		tmp = *b;
		*b = (*b)->next;
		lstadd_front_ps(a, tmp);
	}
}

// pb (push b): Take the first element at the top of a 
// and put it at the top of b.
//Do nothing if a is empty.
void	ft_push_pb_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	else
	{
		tmp = *a;
		*a = (*a)->next;
		lstadd_front_ps(b, tmp);
	}
}

//ra (rotate a): Shift up all elements of stack a by 1.
void	ft_rotate_ra_b(t_stack **a)
{
	t_stack	*head;
	t_stack	*last;

	head = *a;
	last = lstlast_ps(*a);
	*a = head->next;
	last->next = head;
	head->next = NULL;
}

//rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rotate_rb_b(t_stack **b)
{
	t_stack	*head;
	t_stack	*last;

	head = *b;
	last = lstlast_ps(*b);
	*b = head->next;
	last->next = head;
	head->next = NULL;
}

//rr : ra and rb at the same time.
void	ft_rotate_rr_b(t_stack **a, t_stack **b)
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
}
