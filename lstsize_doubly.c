/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize_doubly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:00 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 14:41:34 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Counts the number of nodes in a list.
*/
int	lstsize_doubly(t_stack *lst)
{
	int	counter;
	t_stack *head;
	head = lst;
	
	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
		if(lst == head)
			break;
	}
	return (counter);
}
