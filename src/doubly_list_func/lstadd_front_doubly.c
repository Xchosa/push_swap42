/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front_doubly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:23:12 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 11:47:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
lst: The address of a pointer 
to the first link of a list.
new: The address of a pointer 
to the node to be added to the list.
*/

void	lstadd_front_doubly(t_stack **lst, t_stack *new)
{	
	if(new == NULL)
		return;
	if(*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
	}
	
	if (new != NULL)
	{
		// last_node = (*lst)->prev;
		// last_node->next = new;
		// new->prev = last_node; 
		new->next = *lst;
		(*lst)-> prev = new;
		*lst = new;
	}
}