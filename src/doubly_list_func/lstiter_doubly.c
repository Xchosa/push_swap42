/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_doubly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:42 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 13:43:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/
void	lstiter_doubly(t_stack *lst, void (*f)(t_object *))
{
	t_stack *head;
	
	if(lst == NULL)
		return;
	head = lst;
	while (lst != NULL)
	{
		
		// f(lst->content); wuerde auch func, comp ist intel
		f((t_object *)(lst->content));
		lst = lst->next;
		if (lst == head)
			break;
	}
	
	return ;
}

// maybe 2 functu