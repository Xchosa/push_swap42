/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:28:07 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/28 14:20:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


void	print_content_targetnode(t_stack *data)
{
	ft_printf("data: %d | index:  %d  || targetnode stack b %d  | push_cost %d   |" ,data->data, data->index, data->target->data, data->push_cost);
	if (!(data->above_median))
		ft_printf("above_median false | \n");
	if (data->above_median)
		ft_printf("above_median true | \n");
}

void	print_content_above_median (t_stack *data)
{
	ft_printf("data: %d | index:  %d  || " ,data->data, data->index );
	if (!(data->above_median))
		ft_printf("above_median false | \n");
	if (data->above_median)
		ft_printf("above_median true | \n");
}

void	print_content_targetnode_cheapest (t_stack *data)
{
	ft_printf("data: %d | index:  %d  || " ,data->data, data->index);
	if (!(data->cheapest))
		ft_printf("cheapest false | \n");
	if ((data->cheapest))
		ft_printf("cheapest true\n");
}

void	print_content(t_stack *data)
{
	ft_printf("data: %d | index:  %d " ,data->data, data->index);
	if (!(data->above_median))
		ft_printf("above_median false | ");
	if (data->above_median)
		ft_printf("above_median true | ");
	if(!(data->cheapest))
		ft_printf("cheapest false\n");
	if((data->cheapest))
		ft_printf("cheapest true\n");
	
}

void	print_content_plain(t_stack *data)
{
	ft_printf("data: %d | index:  %d \n" ,data->data, data->index);
}