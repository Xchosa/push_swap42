/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/14 14:35:08 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/
void	lstiter_ps(t_stack *lst, void (*f)(t_stack *))
{
	t_stack *head;
	
	if(lst == NULL)
		return;
	head = lst;
	while (lst != NULL)
	{
		// f((t_stack *)(lst->data));
		f(lst);
		lst = lst->next;
		// if (lst == head)
		// 	break;
	}
	
	return ;
}

