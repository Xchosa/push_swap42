/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 16:55:31 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


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


// typedef struct s_stack_list
// {
// 	void			*content;
// 	int				*nbr;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }					t_stack_list;

void del( void *content)
{
	free(content);
}

void print_content(int nbr)
{
	ft_printf("%d\n", nbr);
}
// void check_sorted(int nbr)
// {
	
// }

void ft_swap_2nbr(t_stack**a)
{
	if(((*a)-> next ) > (*a))
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
	else
		lstiter_doubly(*a, print_content);
	lstclear_doubly(a, del);
}

void ft_swap(t_stack **a)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	t_stack	*last;
	
	first	= *a;
	second	= (*a)->next;
	third	= second->next;
	last	= lstlast_doubly(*a);
	
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	first->next = third;
	
	if(third != NULL)
		third->prev = first;
	if(last != NULL)
		last->next = second;
	
	// if (second->prev != NULL)
    // second->prev->next = second;
	// else
    // last->next = second;
	
	*a	= second;
}
// sa (swap a): Swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
void ft_sa(t_stack **a)
{
	// t_stack *second;
	// t_stack *first ;
	// first = *a;
	// second = (*a)->next;
	// *a = second;
	// (*a)->next = first;
	ft_swap(a);
	write(1, "sa\n", 3);
}

void ft_sb(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

// void ft_ss(t_stack **a, t_stack **b)
// {
// 	ft_swap(a);
// 	ft_swap(b);
// 	write(1, "ss\n", 3);
// }