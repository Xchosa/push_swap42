/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b_into_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:01:20 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/29 11:04:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// find target node for every b node in stack a
// target = closest smaller Num in stack a;
// if no smaller Num found , target node in a stack will be the biggest nbr in stack a
void target_of_a_in_stack_b(t_stack **a, t_stack **b)
{
	int		smallest_differents;
	t_stack *current_a;
	t_stack *current_b;
	
	current_b = *b;
	while(current_b != NULL)
	{
		smallest_differents = INT_MAX;
		current_a = *a;
		while(current_a!= NULL)
		{
			if ((current_b)->data > (current_a)->data)
			{
				if ((current_b)->data - (current_a)->data < smallest_differents)
				{
					smallest_differents = (current_b)->data - (current_a)->data ;
					(current_b)->target = current_a;
				}
			}
			current_a = current_a->next;
		}
		if (smallest_differents == INT_MAX)
			(current_a)->target = get_min_max_totalstack(b);
		(current_a) = (current_a)->next;
	}
}