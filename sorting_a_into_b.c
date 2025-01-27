/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/27 12:09:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// if stack is bigger than 5 , sorting and push lowest Nr on top, than the next 
// to top of b . Highest Nr on top of stack b. 
// stack a (last 3 ) sortet 
void	chose_sorting(t_stack **a, t_stack **b)
{
	if (lstsize_ps(*a) <= 5)
	{
		if(lstsize_ps(*a) == 3)
			sort_three(a);
		if(lstsize_ps(*a) == 2)
			sort_two(a);
		if(lstsize_ps(*a) == 4)
			sort_four(a, b);
		if(lstsize_ps(*a) == 5)
			sort_five(a, b);
		return;
	}
	else
		turkswapsorting(a, b);
}


// sort to stack B. Higgehst Nr on top.
 
void turkswapsorting(t_stack **a,t_stack **b)
{
	ft_push_pb(a, b);
	ft_push_pb(a, b);
	give_index(a);
	give_index(b);
	sort_2_descending(b);
	printf("Stack B bevor algo \n");
	lstiter_ps(*b, print_content);
	printf("Stack A bevor algo \n");
	lstiter_ps(*a, print_content);
	target_of_a_in_stack_b(a,b);
	printf("Stack A targetnodes \n");
	lstiter_ps(*a, print_content_targetnode);
	
	
	// pushing back b to a. 
	// rotate until closet higher nr on top of a,
	// pb from b to a. 
}
// find target node for every a node in stack b
// target = closest smaller Num in stack b;
// if no smaller Num found , target node in a stack will be the biggest nbr in stack b
void target_of_a_in_stack_b(t_stack **a, t_stack **b)
{
	int		smallest_differents;
	t_stack *current_a;
	t_stack *current_b;
	
	current_a = *a;
	while(current_a != NULL)
	{
		smallest_differents = INT_MAX;
		current_b = *b;
		while(current_b!= NULL)
		{
			if ((current_a)->data > (current_b)->data)
			{
				if ((current_a)->data - (current_b)->data < smallest_differents)
				{
					smallest_differents = (current_a)->data - (current_b)->data ;
					(current_a)->target = current_b;
				}
			}
			current_b = current_b->next;
		}
		if (smallest_differents == INT_MAX)
			(current_a)->target = get_max_nbr_totalstack(b);
		(current_a) = (current_a)->next;
	}
}
// moves to bring a on top
// + moves to bring a-targetnode on top (in stack b)
void calc_steps_for_cheapest_move(t_stack **a, t_stack **b)
{
	
}
