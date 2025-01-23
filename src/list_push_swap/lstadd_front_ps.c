/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:23:12 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/23 15:55:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
lst: The address of a pointer 
to the first link of a list.
new: The address of a pointer 
to the node to be added to the list.
*/

void	lstadd_front_ps(t_stack **lst, t_stack *new)
{	
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	// lstlast_ps(*lst)->next = new;
}