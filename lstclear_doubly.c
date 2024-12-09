/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_doubly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:19:13 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:36:21 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Deletes and frees the given node and every 
successor of that node, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
*/

void	ft_llstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*tmp;
	t_stack *start;
	
	if(lst == NULL)
		return;
	start = *lst;

	while (*lst != NULL)
	{
		tmp = (*lst)-> next;
		del((*lst)->content);
		//del((*lst)->nbr); not dynm alloc , content can point dynamc to alloc memorry
		free(*lst);
		*lst = tmp;
		if(*lst  == start)
			break;
	}
	*lst = NULL;
}
