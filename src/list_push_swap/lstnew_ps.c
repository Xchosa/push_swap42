/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:12 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/17 14:43:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
allocates (with malloc(3)) and returns a new node. 
The member variable ’content’ is initialized with 
the value of the parameter 
’content’. The variable ’next’ is initialized to NULL.
*/
t_stack	*lstnew_ps(int content)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> data = content;
	node -> next = NULL;
	return (node);
}
