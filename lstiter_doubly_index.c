/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_doubly_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:36:12 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/12 16:16:31 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./push_swap.h"

/*
Iterates the list ’lst’ and applies the function ’f’ 
on the content of each node.
takes input int index (not nbr)
*/

// void lstiter_doubly_index(t_stack *lst, void (*f)(int index))
// {
// 	t_stack *head;
// 	index = 1;
// 	if(lst == NULL)
// 		return;
// 	head = lst;
// 	while (lst != NULL)
// 	{
// 		// f(lst->nbr);
// 		f(lst->index);
// 		index++;
// 		lst = lst->next;
// 		if (lst == head)
// 			break;
// 	}
// 	return ;
// }
