/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:44:43 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/17 15:45:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// swapping
// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

// pushing (top to bottom/ bottom to top)
// pa (push a): Take the first element at the top of b and put it at the top of a.
// 	Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// 	Do nothing if a is empty.

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

//pb (push b): Take the first element at the top of a and put it at the top of b.
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

//ra (rotate a): Shift up all elements of stack a by 1.
void ft_rotate_ra (t_stack **a)
{
	t_stack *head;
	t_stack *last;
	// t_stack *prelastnode;
	head = *a;
	last = lstlast_ps(*a);
	ft_printf("ra\n");
	*a = head->next;
	last->next = head;
	head->next = NULL;	
}

//rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
void ft_rotate_rb (t_stack **b)
{
	t_stack *head;
	t_stack *last;
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
	t_stack *head;
	t_stack *last;
	
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

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	ft_rotate_rra(t_stack **a)
{
	t_stack *head;
	t_stack *lastnode;
	t_stack *second_last;
	
	if( (*a == NULL ) || ((*a)->next == NULL))
		return;
		
	head = *a;
	lastnode = lstlast_ps(*a);
	second_last = *a;
	
	while(second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	lastnode->next = head;
	*a = lastnode;
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

void	ft_rotate_rrb(t_stack **b)
{
	t_stack *head;
	t_stack *lastnode;
	t_stack *second_last;
	
	if( (*b == NULL ) || ((*b)->next == NULL))
		return;
		
	head = *b;
	lastnode = lstlast_ps(*b);
	second_last = *b;
	
	while(second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	lastnode->next = head;
	*b = lastnode;
	ft_printf("rrb\n");
}
// rrr : rra and rrb at the same time.
void	ft_rotate_rrr(t_stack **a, t_stac)
{
	t_stack *head;
	t_stack *lastnode;
	t_stack *second_last;
	
	if( (*b == NULL ) || ((*b)->next == NULL))
		return;
		
	head = *b;
	lastnode = lstlast_ps(*b);
	second_last = *b;
	
	while(second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
	lastnode->next = head;
	*b = lastnode;
	ft_rotate_rrr(t_stack )
}