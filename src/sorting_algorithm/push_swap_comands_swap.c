/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comands_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:15:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/13 09:50:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	ft_swap_sa(t_stack **a)
{
	t_stack	*head;
	t_stack	*second_head;

	head = *a;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*a = second_head;
	ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
void	ft_swap_sb(t_stack **b)
{
	t_stack	*head;
	t_stack	*second_head;

	head = *b;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*b = second_head;
	ft_printf("sb\n");
}

void	ft_swap_ss(t_stack **a, t_stack **b)
{
	t_stack	*head;
	t_stack	*second_head;

	head = *a;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*a = second_head;
	head = *b;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*b = second_head;
	ft_printf("ss\n");
}
