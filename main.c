/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/28 14:21:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


// sortieren
// linked list - ohne das es auf den Anfang zeigt
// turk swap. 



//teste push und rotate , rb ra , rr 



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
	if(parse_result == EXIT_FAILURE )
	{
		// lstiter_ps(a, del);
		return(EXIT_FAILURE);
	}
	// printf("Stack A before: \n");
	// lstiter_ps(a, print_content);
	printf("\n");
	
	chose_sorting(&a,&b);
	
	
	
	// printf("Stack A after sorting: \n");
	// lstiter_ps(a, print_content); 
	// ft_printf("\n");
	// printf("Stack B after sorting : \n");
	// lstiter_ps(b, print_content);
	// printf("\n");
	
	
	// if(!check_order(&a))
	// 	ft_printf("a not sorted");
	// else
	// 	ft_printf("a is sorted");
	
	// ft_printf("\n");
	// printf("Stack A after sorting: \n");
	// lstiter_ps(a, print_content); 
	// ft_printf("\n");
	// printf("Stack B after sorting : \n");
	// lstiter_ps(b, print_content);
	// printf("\n");
	// free_stack (a)
	// ft_sa(&a);
	
}


// void del( t_stack *data)
// {
// 	ft_printf("data");
// 	free(data->data);
// }
// wenn fail alle nodes freen. 

