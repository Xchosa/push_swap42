/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backdb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:20:34 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/05 17:37:16 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_lstadd_backdb(t_llist **lst, t_llist *new)
{
	t_llist	*last_node;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	else
	{
		last_node = ft_lstlastdb(*lst);
		last_node->next = new;
		new->prev = last_node;
		new->next = *lst;
		(*lst)->prev = new;
	}
}