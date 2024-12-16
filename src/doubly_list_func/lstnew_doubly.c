/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_doubly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:12 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 12:18:41 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
allocates (with malloc(3)) and returns a new node. 
The member variable ’content’ is initialized with 
the value of the parameter 
’content’. The variable ’next’ is initialized to NULL.
*/

// t_stack	*lstnew_doubly(int nbr)
// {
// 	t_stack	*node;

// 	node = malloc (sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->nbr = nbr;
// 	node->content = NULL;
// 	node->next = NULL;
// 	node->prev = NULL;
// 	return (node);
// }

t_stack	*lstnew_doubly(t_object *object)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	// object = malloc(sizeof(t_object));
	// if (!object)
	// 	{
	// 	free(node);
	// 	return (NULL);
	// 	}
	node->content = (void *)object;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// content erwartet einen void pointer 