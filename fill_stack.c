/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:41:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/20 15:01:32 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void put_index(t_stack *data)
{
	data->index++;
	// bubbelsort nach kleinster nummer 
	// 
	// einen Loop kleinste 
	// bubbelsort 
}

void print_content(t_stack *data)
{
	ft_printf("data: %d | index:  %d\n", data->data, data->index);
}



// find closest smalest nbr
// void find_target_b(t_stack **a, t_stack **b)
// {
// 	t_stack *tmp;
// 	t_stack *closest;
// 	int		minimal_diff;
	
// 	while(*a != NULL)
// 	{
// 		closest = NULL;
// 		minimal_diff = INT_MAX;
// 		tmp = b;
// 		while(tmp != NULL)
// 		{
// 			if(tmp ->data < a->data && (a->data ))
// 		}
// 	}
// }