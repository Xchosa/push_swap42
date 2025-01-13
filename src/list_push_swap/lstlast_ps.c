/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_doubly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:39:51 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/09 14:52:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
returns the last node of the list.
*/
t_stack	*lstlast_ps(t_stack *lst)
{
	t_stack *tmp;
	
	if (lst == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp -> next;
	}
	return (tmp);
}


// void	ft_lstadd_backdb(t_stack **lst, t_stack *new)
// {
// 	t_stack	*last_node;

// 	if (new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		new->next = new;
// 		new->prev = new;
// 		return ;
// 	}
// 	else
// 	{
// 		last_node = ft_lstlastdb(*lst);
// 		last_node->next = new;
// 		new->prev = last_node;
// 		new->next = *lst;
// 		(*lst)->prev = new;
// 	}
// }