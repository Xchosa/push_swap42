/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/17 14:42:16 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/
void	lstiter_ps(t_stack *lst, void (*f)(t_stack *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
	return ;
}
