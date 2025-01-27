/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/27 16:45:17 by poverbec         ###   ########.fr       */
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
	give_index_and_median(a);
	sort_2_descending(b);
	
	//testing
	printf("Stack B bevor algo \n");
	lstiter_ps(*b, print_content);
	printf("Stack A bevor algo \n");
	lstiter_ps(*a, print_content);
	
	target_of_a_in_stack_b(a,b);// nodes in a get a target node in b// works
	// while loop until stack a = 3 
	give_index_and_median(b); // reset index, median, 
	// give all cheapest to false 
	printf("Stack A targetnodes \n");
	lstiter_ps(*a, print_content_targetnode);
	printf("Stack B targetnodes \n");
	lstiter_ps(*b, print_content_above_median);

	int push_costs = calc_steps_for_cheapest_move(a, b); // cheapest in stack b is marked "cheapest true"
	printf("Stack B cheapest\n");
	lstiter_ps(*b, print_content_targetnode_cheapest);
	
	printf("push_costs %d\n", push_costs);
	printf("Stack B reset cheapest\n");
	lstiter_ps(*b, reset_cheapest);
	lstiter_ps(*b, print_content_targetnode_cheapest);
	
	
	
	
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
// braucht man beachten wo node a ist? bisher wieviele schritte braucht man um die targetnode f
int calc_steps_for_cheapest_move(t_stack **a, t_stack **b)
{
	int push_costs;
	int smallest_push_costs;
	
	smallest_push_costs = INT_MAX;
	t_stack *current_a;
	t_stack *current_b;
	current_a = *a;
	while(current_a != NULL)
	{
		push_costs = 0;
		if(current_a->target->above_median == true && current_a->target != NULL)
		{
			current_b = *b;
			while (current_a->target != current_b && current_b != NULL) // costen nach oben zu bringen. 
			{
				current_b = current_b ->next;
				push_costs++;
			}
			if (push_costs <= smallest_push_costs)
			{
				smallest_push_costs = push_costs;
				lstiter_ps(current_b, reset_cheapest); // only current_a target lowest_push cost gets cheapest 
				current_b->cheapest = true;// migth be more than one cheapest - first one will be chosen
			}
		}
		else if(current_a->target->above_median ==false && current_a->target != NULL)
		{
			current_b = *b;
			while (current_a->target != current_b && current_b != NULL)
			{
				push_costs = ((lstlast_ps(current_b)->index) - current_b->index) + 1;
				current_b = current_b ->next;
			}
			if (push_costs <= smallest_push_costs && current_b != NULL)
			{
				smallest_push_costs = push_costs;
				lstiter_ps(current_b, reset_cheapest);
				current_b->cheapest = true;// migth be more than one cheapest - first one will be chosen
			}
		}
		current_a = current_a ->next;
	}
	return(smallest_push_costs);
}

void move_cheapest_node_in_a_and_b_to_top(t_stack **a, t_stack **b)
{
	t_stack *current_a;
	current_a = *a;
	if()
	while (current_a->target->cheapest != true) 
		current_a= current_a ->next 
}

