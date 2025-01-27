/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:07 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:43 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


void	print_content_targetnode(t_stack *data)
{
	ft_printf("data: %d | index:  %d  || targetnode stack b %d\n " ,data->data, data->index, data->target->data);
}