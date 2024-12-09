/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_doubly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:39:51 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:36:45 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
returns the last node of the list.
*/
t_list	*ft_llstlast(t_stack *lst)
{
	t_stack *tmp;
	t_stack *prev;
	t_stack *head;
	
	//head fixieren
	
	if (lst == NULL)
		return (NULL);
	head = &lst;
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
		lst->prev = tmp;
	}
	return (lst);
	
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