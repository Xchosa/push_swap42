/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:02:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/21 14:16:46 by poverbec         ###   ########.fr       */
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
	if(check_duplicates(a) == 1)
		return(EXIT_FAILURE);
	else 
		return(EXIT_SUCCESS);	
}
		
// mulitple Arguments 
int parse_data_multiple_arg(char **argv, t_stack **a )
{	
	int		i;
	int		nbr;
	t_stack *stack_lst;

	i = 0;
	while (argv[i] != NULL)
		{	
			nbr = ft_atol(argv[i]);
			if(nbr < INT_MIN || nbr > INT_MAX)
			{
			ft_printf("INT_MIN: %d", nbr);
			return(EXIT_FAILURE);
			}
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
		if(check_duplicates(a) == 1)
			return(EXIT_FAILURE);
		else 
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
		parse_result = parse_data_multiple_arg((argv + 1), a);
		return(parse_result);
	}
	return (EXIT_FAILURE);
}

int	check_duplicates(t_stack **stack)
{
	t_stack *current;
	t_stack *check;
	current = *stack;
	check = current->next;
	
	
	while(current->next != NULL)
	{
		while(check->next != NULL)
		{
			if(current->data == check->data)
			{
				ft_printf("doubble");
				return(EXIT_FAILURE);
			}
			else
				check  = check->next;
		}
		current = current->next;
		check = current->next;
	}
	return(EXIT_SUCCESS);
}
