/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 14:05:01 by poverbec         ###   ########.fr       */
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
	// int check = check_duplicates(&a);
	if(parse_result == EXIT_FAILURE )
	{
		// lstiter_ps(a, del);
		return(EXIT_FAILURE);
	}
	// if(argc == 3)
	// 		return(ft_swap_2nbr(&a),0);
	printf("Stack A before: \n");
	// lstiter_ps(a, put_index);
	lstiter_ps(a, print_content);
	lstiter_ps(a, put_index);
	printf("\n");
	if(lstsize_ps(a)== 2)
		// sort_two
	if(lstsize_ps(a) == 3)
		sort_three(&a);
	// printf("Stack B before: \n");
	lstiter_ps(b, print_content);

	
	// sort(&a, &b);
	// ft_push_a(&a, &b);
	ft_push_a(&a, &b);
	ft_push_a(&a, &b);
	printf("Stack A after inital: \n");
	lstiter_ps(a, print_content); 
	ft_printf("\n");
	printf("Stack B after inital : \n");
	lstiter_ps(b, print_content);
	printf("\n");
	// ft_push_b(&b, &a);
	// ft_push_a(&a, &b);
	// ft_rotate_rr(&b , &a);
	// ft_rotate_rra(&a);
	//ft_rotate_rrr(&a, &b);
	// ft_swap_sb(&b);
	//ft_swap_sa(&a);
	// ft_swap_ss(&a, &b);
	sort_three(&a);
	
	if(!check_order(&a))
		ft_printf("a not sorted");
	else
		ft_printf("a is sorted");
	
	ft_printf("\n");
	printf("Stack A after operation: \n");
	lstiter_ps(a, print_content);
	printf("\n");
	printf("Stack B after: \n");
	lstiter_ps(b, print_content);
	// free_stack (a)
	// ft_sa(&a);
	
}


// void del( t_stack *data)
// {
// 	ft_printf("data");
// 	free(data->data);
// }
// wenn fail alle nodes freen. 

