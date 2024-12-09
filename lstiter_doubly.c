/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_doubly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:42 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:36:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/
void	ft_llstiter(t_stack *lst, void (*f)(void *))
{
	t_stack *head;
	
	if(lst == NULL)
		return;
	head = lst;
	while (lst != NULL)
	{
		// f(lst->nbr);
		f(lst->content);
		lst = lst->next;
		if (lst == head)
			break;
	}
	
	return ;
}

// maybe 2 functu