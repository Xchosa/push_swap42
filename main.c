/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/14 16:46:35 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// stack initieren
// drucken lassen
// befehle implementieren
// sortieren
// linked list - ohne das es auf den Anfang zeigt
// turk swap. 


// nodes iniatlisieren
int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		parse_result;

	a = NULL;
	b = NULL;
	if(argc < 2)
		return (EXIT_SUCCESS);
	parse_result = start_parse(argc, argv, &a);
	if(parse_result == EXIT_FAILURE)
	{
		// lstiter_ps(a, del);
		return(EXIT_FAILURE);
	}
	// if(argc == 3)
	// 		return(ft_swap_2nbr(&a),0);
	
	lstiter_ps(a, print_content);
	sort(&a, &b);
	lstiter_ps(a, print_content);
	lstiter_ps(b, print_content);
	// ft_sa(&a);
	
}

