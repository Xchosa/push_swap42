/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastdb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:39:51 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/05 17:51:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
returns the last node of the list.
*/
t_list	*ft_lstlastdb(t_llist *lst)
{
	t_llist *tmp;
	t_llist *prev;
	erste ellement fixieren  head 
	
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
		prev = lst->tmp;
	}
	return (lst);
	
}
