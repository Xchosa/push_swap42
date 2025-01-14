/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/14 14:59:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>


// Exit_SUCCESS 0
// Exit_Failre 1

// check edge cases (int digit, dublicates, empty.  )
// create lst with numbers

// make long to int
// change headder file back to int (from long)
int parse_data(char *data, t_stack **a)
{
	long	 	nbr;
	char 		**split_nbr;
	t_stack 	*stack_lst;
	int			i;

	i = 0;	
	split_nbr = ft_split(data, ' ');
	int j = 0;
	while (split_nbr[j])
	{
		printf("nu = %s\n", split_nbr[j++]);
	}
	
	while(split_nbr[i] != NULL)
	{
		// if(ft_strlen(*data) > 11)
		// {
		// 	ft_printf("42: %d", nbr);
		// 	return(EXIT_FAILURE);
		// }
		printf("test vor atol\n");
		nbr = ft_atol(split_nbr[i++]);
		ft_printf("43: %d\n", nbr);
		if(nbr < INT_MIN || nbr > INT_MAX)
		{
			ft_printf("INT_MIN: %d", nbr);
			return(EXIT_FAILURE);
		}
		// check for dublicates 42 and 42
		stack_lst = lstnew_ps(nbr);
		if(!stack_lst)
		{
			ft_printf("failed stack: %d", nbr);
			return(EXIT_FAILURE);
		}
		if(*a == NULL)
			*a = stack_lst;
		else
			lstadd_back_ps(a, stack_lst);
	}
	return(EXIT_SUCCESS);
}
		


int start_parse(int argc, char **argv, t_stack **a )
{
	int 	parse_result;
	
	// case for argc == 2
	
	if(argc > 1 )
	{
		parse_result = parse_data(*(argv + 1), a);
		ft_printf("73 %d\n", parse_result); // Debug print
		return(parse_result);
	}
	return (EXIT_FAILURE);
}


void del( void *data)
{
	free(data);
}

void print_content(t_stack *data)
{
	ft_printf("data: %d\n", data->data);
}
// ft_printf("data: %i, Nbr: %d, Index_sorted %d\n", object->index, object->nbr, object->index_sorted);


// void check_sorted(t_stack **a, int nbr)
// {
// 	a->next 
// }


// void ft_swap_2nbr(t_stack **a)
// {
// // caste t_object typ auf den pointer content (der in der node *a gespeichert ist)-> auf int nbr pointed
// 	// ft_printf("Before if: %d %d\n", ((t_object*)(*a)->content)->nbr, ((t_object*)(*a)->next)->nbr);
	
// 	if( ((t_object*)(*a)->content)->nbr > ((t_object*)(*a)->next->content)->nbr)
// 	{
// 		ft_swap_only(a);
// 		write(1, "sa\n", 3);
// 		lstiter_doubly(*a, print_content);
// 	}
// 	else
// 	{
// 		ft_printf("no swap %d\n",((t_object*)(*a)->content)->nbr);
// 		ft_printf("%d",((t_object*)(*a)->next->content)->nbr);
// 		// lstiter_doubly(*a, print_content);
// 	}
// 	// lstiter_doubly(*a, print_content);
// 	lstclear_doubly(a, del);
// }



