/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/09 16:41:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// stack initieren
// drucken lassen
// befehle implementieren
// sortieren
// linked list - ohne das es auf den Anfang zeigt
// turk swap. 

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		parse_result;

	a = NULL;
	b = NULL;
	if(argc < 2)
		return (EXIT_SUCCESS); // stdlib
	parse_result = start_parse(argc, argv, &a)
	// if(argc == 3)
	// 		return(ft_swap_2nbr(&a),0);
	if(parsing)
	
	lstiter_doubly(a, print_content);
	
	
	ft_sa(&a);
	
}

