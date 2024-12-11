/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 13:27:10 by poverbec         ###   ########.fr       */
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


void swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;

	
}

void ft_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void ft_sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void ft_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}