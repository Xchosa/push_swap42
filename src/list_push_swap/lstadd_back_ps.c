/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:20:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/23 15:55:22 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Adds the node ’new’ at the end of the list.
*/

void	lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		last_node = lstlast_ps(*lst);
		last_node->next = new;
	}
	// new->next = *lst;
	// return;
}