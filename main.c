/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/30 14:47:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

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
		if (a != NULL)
			free_stack(&a);
		ft_printf("Error\n");
		return(EXIT_FAILURE);
	}
	if((check_order(&a)== 1 || lstsize_ps(a) == 1))
	{
		free_stack(&a);
		// lstiter_ps(a, print_content);
		return(EXIT_SUCCESS);
	}
	chose_sorting(&a,&b);
	return(EXIT_SUCCESS);
}
// printf("Stack A after: \n");
// lstiter_ps(a, print_content);
// printf("Stack A before: \n");
// lstiter_ps(a, print_content);

// void del( t_stack *data)
// {
// 	ft_printf("data");
// 	free(data->data);
// }
// wenn fail alle nodes freen. 

