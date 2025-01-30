/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b_into_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:01:20 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/30 12:35:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// find target node for every b node in stack a
// target = closest BIGGER Num in stack a;
// if no smaller Num found , target node in a stack will be the biggest nbr in stack a
void target_of_b_in_stack_a(t_stack **a, t_stack **b)
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
			if ((current_b)->data < (current_a)->data)
			{
				if ((current_a)->data - (current_b)->data < smallest_differents)
				{
					smallest_differents = (current_a)->data - (current_b)->data ;
					(current_b)->target = current_a;
				}
			}
			current_a = current_a->next;
		}
		if (smallest_differents == INT_MAX)
			(current_b)->target = get_min_nbr_totalstack(a);
		current_b = current_b->next;
	}
}
void moving_b_node_to_target_b(t_stack **a, t_stack **b)
{
	int i;
	if((*b)->target->above_median)
	{
		i = ((*b)->target->index);
		while (i > 0)
		{
			ft_rotate_ra(a);
			i--;
		}
	}
	else 
	{
		i = lstsize_ps(*a) - ((*b)->target->index);
		while (i > 0)
		{
			ft_rotate_rra(a);
			i--;
		}
	}
}

void	 smallest_on_top_a(t_stack **a)
{
	while((*a)->data != get_min_nbr_totalstack(a)->data)
	{
		if(get_min_nbr_totalstack(a)->above_median)
			ft_rotate_ra(a);
		else
			ft_rotate_rra(a);
	}
}