/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a_into_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:54 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/23 18:31:20 by poverbec         ###   ########.fr       */
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
	//lstiter_ps(*a, print_content);
	// lstiter_ps(*b, print_content); 
	sort_2_descending(b);
	set_target_in_a(a,b);
	// lstiter_ps(*b, print_content);
	// lstiter_ps(*a, print_content); 
	// set_target(a, b);
	// int i = 0;
	// while(lstsize_ps(*a) > 3 || i < 10)
	// {
		
	// 	i++;
	// }
	// sort_three(a);

	
	// pushing back b to a. 
	// rotate until closet higher nr on top of a,
	// pb from b to a. 
}

