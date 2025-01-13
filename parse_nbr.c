/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/13 17:37:12 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


// Exit_SUCCESS 0
// Exit_Failre 1

// check edge cases (int digit, dublicates, empty.  )
// create lst with numbers


int parse_input(char **data, t_stack **a)
{
	ssize_t nbr;
	t_stack *stack_lst;
	
	while(*data != NULL)
	{
		if(ft_atol(*data) != LONG_MIN)
		{
			ft_printf("no digit");
			return(EXIT_FAILURE);
		}
		if(ft_strlen(*data)< 11)
			nbr = ft_atoi(*data);
		else
			return(EXIT_FAILURE);
		if(nbr < INT_MIN || nbr > INT_MAX)
			return(EXIT_FAILURE);
		// check for dublicates 42 and 42
		stack_lst = lstnew_ps(nbr);
		if(!stack_lst)
			return(EXIT_FAILURE);
		else
			lstadd_back_ps(a, stack_lst);
		data++;
	}
	return(EXIT_SUCCESS);
}


int start_parse(int argc, char **argv, t_stack **a )
{
	int 	parse_result;
	// case for argc == 2
	if(argc >2)
	{
		parse_result = parse_input(argv + 1, a);
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
	ft_printf("data: %i\n", data);
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



