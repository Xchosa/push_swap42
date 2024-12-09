/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_doubly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:12 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:36:52 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
allocates (with malloc(3)) and returns a new node. 
The member variable ’content’ is initialized with 
the value of the parameter 
’content’. The variable ’next’ is initialized to NULL.
*/

t_stack	*ft_llstnew(int nbr)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->content = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}