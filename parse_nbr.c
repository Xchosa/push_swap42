/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/17 11:32:58 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


// Exit_SUCCESS 0
// Exit_Failre 1

// Numbers are all in argument one. 
int parse_data(char *data, t_stack **a)
{
	long	 	nbr;
	char 		**split_nbr;
	t_stack 	*stack_lst;
	int			i;

	i = 0;	
	split_nbr = ft_split(data, ' ');
	
	while(split_nbr[i] != NULL)
	{
		nbr = ft_atol(split_nbr[i]);
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
		i++;
	}
	return(EXIT_SUCCESS);
}
		
// mulitple Arguments 
int parse_data_multiple_arg(char **argv, t_stack **a )
{	
	int		i;
	int		nbr;
	t_stack *stack_lst;
	
	// ft_printf("argc arguments: %d\n", argc);
	i = 0;
	while (argv[i] != NULL)
		{	
			nbr = ft_atol(argv[i]);
			// ft_printf("nbr  %d \n ", nbr);
			if(nbr < INT_MIN || nbr > INT_MAX)
			{
			ft_printf("INT_MIN: %d", nbr);
			return(EXIT_FAILURE);
			}
			stack_lst = lstnew_ps(nbr);
			// ft_printf("stack_lst %d \n ", stack_lst->data);
			if(!stack_lst)
			{
				ft_printf("failed stack: %d", nbr);
				return(EXIT_FAILURE);
			}
			if(*a == NULL)
				*a = stack_lst;
			else
				lstadd_back_ps(a, stack_lst);
			i++;
		}
		// ft_printf("failed stack: %d", );
		// lstiter_ps(*a, print_content);
		//wenn alle nodes erstellt sind 
		// check for dublicates 42 and 42 // nr 1 schaut auf alle danach, pos 4 schaut nicht mehr pos 3 an // 
		return(EXIT_SUCCESS);
}


int start_parse(int argc, char **argv, t_stack **a )
{
	int 	parse_result;
	
	if(argc == 2 )
	{
		parse_result = parse_data(argv[1] , a);
		return(parse_result);
	}
	if (argc > 2)
	{
		// ft_printf("do i reach parse mulitple? 1 \n: %d", argv[3]);
		parse_result = parse_data_multiple_arg((argv + 1), a);
		return(parse_result);
	}
	return (EXIT_FAILURE);
}



void print_content(t_stack *data)
{
	ft_printf("data: %d | index:  %d\n", data->data, data->index);
}

// void put_index(t_stack **a)
// {
// 	// bubbelsort nach kleinster nummer 
// 	// 
// 	// einen Loop kleinste 
// 	// bubbelsort 
	
// }
// ft_printf("data: %i, Nbr: %d, Index_sorted %d\n", object->index, object->nbr, object->index_sorted);
