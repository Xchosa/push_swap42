/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:44:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/16 17:06:50 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// swapping
// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

// pushing (top to bottom/ bottom to top)
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// rotating 
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

// turk sort ab bestimmter groeser, davor anderer sort
// am besten combinieren. 

void ft_push_a(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	if(*a == NULL)
		return;
	else
		tmp = *a;
		*a = (*a)->next;
		lstadd_front_ps(b, tmp);
		ft_printf("pa\n");
}

void ft_push_b(t_stack **b, t_stack **a)
{
	t_stack *tmp;
	if(*b == NULL)
		return;
	else
		tmp = *b;
		*b = (*b)->next;
		lstadd_front_ps(a, tmp);
		ft_printf("pb\n");
}

void ft_rotate_ra (t_stack **a)// erster zur lezten und letzten zu erst 
{
	t_stack *head;
	t_stack *last;
	// t_stack *prelastnode;
	head = *a;
	last = lstlast_ps(*a);
	*a = head->next;
	last->next = head;
	head->next = NULL;
	
	// head = *a;
	// prelastnode = prelast(*a, last);
	
	// last->next = head->next; // beide auf zweite 
	// head->next = NULL;
	// // vorletzte node next muss auf neue letzte zeigen. also head.
	// t_stack *tmp;
	// tmp = head;
	// head = last;
	// last = tmp;	

	// prelastnode->next = head;
	
}

// t_stack *prelast( t_stack *stack, t_stack *last)
// {
	
// 	t_stack *prelast = stack;
// 	while(prelast->next != last)// data vergleichen in der node // oder pointer adressen
// 	{
// 		prelast = prelast->next;
// 	}
// 	return (prelast);
// }

// void ft_rotate_ra (t_stack **a)
// {
	
// }

// void ft_rr()
// {
	
// }