/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:35:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/11 16:38:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	ft_swap_sa_b(t_stack **a)
{
	t_stack	*head;
	t_stack	*second_head;

	head = *a;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*a = second_head;
}

// sb (swap b): Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
void	ft_swap_sb_b(t_stack **b)
{
	t_stack	*head;
	t_stack	*second_head;

	head = *b;
	second_head = head->next;
	head->next = second_head->next;
	second_head->next = head;
	*b = second_head;
}

void	ft_swap_ss_b(t_stack **a, t_stack **b)
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
}
