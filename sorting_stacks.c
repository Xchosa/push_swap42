/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:16:19 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 14:28:31 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// cloest smaler number is re
// t_stack *cheapest_node_reachable(t_stack **stack)
// {
// 	t_stack cheapest;
// 	// operations to bring a on top
// 	//operations to bring a->target node on top = push cost

// 	if(a->data <  b->data)
// 		ft_push_a(&a);
// }

void sorting_more(t_stack **a, t_stack **b)
{
	int size_stack;
	t_stack *min_nbr;
	size_stack = lstsize_ps(a);
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_a(a, b);
		size_stack--;
	}
	if(size_stack > 3 && !check_order(a))
	{
		ft_push_a(a, b);
		size_stack--;
	}
	while(size_stack > 3 && !check_order(a))
	{
		
		size_stack--;
	}
	ft_push_a(a, b);
	ft_push_a(a, b);
	sort_three(b); // 
	// min_nbr =  get_min_nbr_totalstack(t_stack )
	
}

void cheapest(t_stack **a, t_stack **b)
{
	
}






//find max Number
t_stack *get_max_nbr_totalstack(t_stack **stack)
{
	t_stack *max_nbr;
	t_stack *current_nbr;
	
	current_nbr = *stack;
	max_nbr = *stack;
	
	while( stack != NULL)
	{
		if(max_nbr->data < current_nbr->data)
			max_nbr = current_nbr;
		else
			current_nbr= current_nbr ->next;
	}
	return(max_nbr);
}

//find smallest Number
t_stack *get_min_nbr_totalstack(t_stack **stack)
{
	t_stack *min_nbr;
	t_stack *current_nbr;
	
	current_nbr = *stack;
	min_nbr = *stack;
	
	while( stack != NULL)
	{
		if(min_nbr->data > current_nbr->data)
			min_nbr = current_nbr;
		else
			current_nbr= current_nbr ->next;
	}
	return(min_nbr);
}