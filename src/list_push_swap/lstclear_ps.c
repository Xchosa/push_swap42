/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:19:13 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/09 15:06:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Deletes and frees the given node and every 
successor of that node, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
*/

void	lstclear_ps(t_stack **lst)
{
	t_stack	*tmp;
	
	if(*lst == NULL)
		return;
	while (*lst != NULL)
	{
		tmp = (*lst)-> next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
