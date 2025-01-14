/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:51:09 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/14 16:45:47 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


bool check_order(t_stack *a)
{
	while(a->next != NULL)
	{
		if( a->next->data < a->data)
			return(false);
		a = a->next;
	}
	return(true);
}

// void	start_filling_stack_b()

void sort(t_stack **a, t_stack **b)
{
	int a_stack_size;
	// int b_stack_size;
	
	bool result = false;
	result = check_order(*a);
	ft_printf("is sorted: %d\n", result);
	a_stack_size = lstsize_ps(*a);
	if(a_stack_size > 2 && !check_order(*a))
		ft_push(a, b);
}