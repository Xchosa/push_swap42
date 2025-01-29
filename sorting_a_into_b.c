/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/29 14:20:59 by poverbec         ###   ########.fr       */
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
	t_stack *cheapestnode_a;
	
	ft_push_pb(a, b);
	ft_push_pb(a, b);
	sort_2_descending(b);
	while(lstsize_ps(*a) > 3 )
	{
		give_index_and_median(a);
		give_index_and_median(b); // reset index, median, 
		//testing
		printf("Stack A bevor algo \n");
		lstiter_ps(*a, print_content);
		printf("\n Stack B bevor algo \n");
		lstiter_ps(*b, print_content);
		
		target_of_a_in_stack_b(a,b);// nodes in a get a target node in b// works
	// while loop until stack a = 3 
		printf("\n Stack A Push_cost \n");
		lstiter_ps(*a, print_content_above_median);// give all cheapest to false 
		printf("\n Stack B before algo \n \n");
		lstiter_ps(*b, print_content);

		
		calc_push_cost_in_a(*a, *b);
		// printf("\n Stack A Push_cost \n");
		// lstiter_ps(*a, print_content_targetnode);
	
		cheapestnode_a = find_a_node_for_cheapest_move(a);// cheapest node + its target node
		// ft_printf("cheapest node \n data: %d | index:  %d | pushcost before: %d \n" ,cheapestnode_a->data, cheapestnode_a->index, cheapestnode_a->push_cost);
		cost_to_move_node_to_top(*a, *b, cheapestnode_a);
		// ft_printf("cheapest node \n pushcost: %d | index:  %d  | data : %d \n" ,cheapestnode_a->push_cost, cheapestnode_a->index, cheapestnode_a->data);

		chose_rotate_command(a,b, cheapestnode_a); // functions to rotate or rev rotate
	
		// printf("\n Stack A  \n");
		// lstiter_ps(*a, print_content_plain);
		// printf("\n Stack B with one more \n");
		// lstiter_ps(*b, print_content_plain);
	}
	sort_three(a);
	// while(lstsize_ps(*b) > 0)
	// {
		
		
	// }


	printf("\n Stack A  \n");
	lstiter_ps(*a, print_content_plain);
	printf("\n Stack B with one more \n");
	lstiter_ps(*b, print_content_plain);
	// printf("Stack A median \n");
	// lstiter_ps(*a, print_content_above_median);
	// printf("Stack B median \n");
	// lstiter_ps(*b, print_content_above_median);

	// // int push_costs = calc_steps_for_cheapest_move(a, b); // cheapest in stack b is marked "cheapest true"
	// printf("Stack B cheapest\n");
	// lstiter_ps(*b, print_content_targetnode_cheapest);
	
	// printf("Stack B reset cheapest\n");
	// lstiter_ps(*b, reset_cheapest);
	// lstiter_ps(*b, print_content_targetnode_cheapest);
	
	
	
	
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
// calc push cost 
// only after giving each node in a its struct  int push_cost to move the node to top of stack

// moves to bring a on top
// + moves to bring a-targetnode on top (in stack b)
void calc_push_cost_in_a(t_stack *a, t_stack *b)
{
	int push_cost_a;
	int push_cost_b;
	
	while(a != NULL)
	{
		push_cost_a = 0;
		push_cost_b = 0;
		if(a->above_median)
			push_cost_a = a->index;
		else //(!(a->above_median))
			push_cost_a = (lstlast_ps(a)->index - a->index);
		if(a->target->above_median)
		{
			push_cost_b = a->target->index;
			// printf("a target index %d \n", push_cost_b );
		}
		else //(!(a->target->above_median))
		{
			push_cost_b = (lstlast_ps(b)->index - a->target->index);
			// printf("b target index %d \n", push_cost_b);
		}
		if(a->above_median == a->target->above_median)
		{
			if(push_cost_a > push_cost_b)
				a->push_cost = push_cost_a;
			else
			{
				a->push_cost = push_cost_b;	
			}
		}
		else
		{
			a->push_cost = push_cost_a + push_cost_b;
			// printf("a stack zahl %d , a target zahl %d \n", a->data , a->target->data);
			// printf("else  a->push-cost %d \n", a->push_cost);
			// printf("find -3 pushcost_a %d + pushcost_b %d  \n", push_cost_a, push_cost_b);
		}
		//printf("push_cost a %d , push cost in node a %d , node Nbr %d \n",push_cost_a, a->push_cost, a->data);
		// printf("push_cost b %d , push cost in node b %d \n",push_cost_b, b->push_cost);
		// printf(" Nbr %d  |  a->push-cost %d \n", a->data, a->push_cost);
		a = a->next;
	}
}

// find cheapest node , the node in a with lowest push_cost (given in calc_push_cost_in_a)
// set target_node in b stack on true // dont need it?
t_stack *find_a_node_for_cheapest_move(t_stack **a)
{
	int push_costs;
	int smallest_push_costs;
	
	smallest_push_costs = INT_MAX;
	t_stack *current_a;
	t_stack *cheapest_node;
	current_a = *a;
	while(current_a != NULL)
	{
		push_costs = 0;
		if( smallest_push_costs > current_a->push_cost)
		{
			smallest_push_costs = current_a->push_cost;
			//lstiter_ps(current_a, reset_cheapest);
			// current_a->target->cheapest = true;
			cheapest_node = NULL;
			cheapest_node = current_a;
		}
		else
			current_a = current_a->next;
	}
	return(cheapest_node);
}
// cheapest node in a is found, and has a target_node in b;
// cheapest node is the one needed with the fewest step to move on top, and according to its target node;
// asign each node its own cost to move to top 
// cheapest_node in a to get moved to top and its targetnode in b to get move to top
void cost_to_move_node_to_top(t_stack *a, t_stack *b, t_stack *cheapest_node_a)
{
	int push_cost_a;
	int push_cost_b;
	if(cheapest_node_a->above_median)
		push_cost_a = cheapest_node_a->index;
	if (!(cheapest_node_a->above_median))
		push_cost_a = (lstlast_ps(a)->index +1 - cheapest_node_a->index);
	if(cheapest_node_a->target->above_median)
		push_cost_b = cheapest_node_a->target->index;
	if(!(cheapest_node_a->target->above_median))
		push_cost_b = lstlast_ps(b)->index + 1  - cheapest_node_a->target->index;

	cheapest_node_a->push_cost = push_cost_a;
	cheapest_node_a->target->push_cost = push_cost_b;
}

