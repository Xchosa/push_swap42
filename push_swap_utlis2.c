/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:32:38 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 15:34:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


// pb (push b): Take the first element at the top of 
//a and put it at the top of b.

void ft_push(t_stack **a, t_stack **b)
{
	t_stack *b;
	lstnew_doubly()
	b = *a;
	

}

// pb (push b): Take the first element at the top of 
//a and put it at the top of b.
void ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}