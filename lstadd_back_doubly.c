/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_doubly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:20:34 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 10:27:37 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Adds the node ’new’ at the end of the list.
*/

void	lstadd_back_doubly(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		// new->next = new;
		// new->prev = new;
		return ;
	}
	else
	{
		last_node = (*lst)->prev;
		last_node->next = new;
		new->prev = last_node;
		new->next = *lst;
		(*lst)->prev = new;
	}
}