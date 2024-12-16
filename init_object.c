/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:15:53 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 12:30:54 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_object	*init_object(t_object *object, int index, int nbr, int index_sorted)
{
	object->index = index; // or any default value
	object->nbr = nbr; // Set the nbr field to the given number
	object->index_sorted = index_sorted; // or any default value
	return (object);
}