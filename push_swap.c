/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 16:30:06 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if((argc == 1) || (argc == 2 && !argv[1][0] ))
		return (0);
	// else if (argc == 2)
	// 	argv = split(argv[1], ' ') jedes argument ist eine zahl ()

	int i;
	i = 1;
	t_stack *node;
	int max_arguments;
	
	while(i < argc )
	{
		node = lstnew_doubly(ft_atoi(argv[i]));
		if(!node)
			return(lstclear_doubly(&a, del), 1);
		if(argc == 3)
			return(ft_swap_2nbr(&a),0);
		lstadd_back_doubly(&a,node);
		i++;
	}
	lstiter_doubly(a, print_content);
	max_arguments = lstsize_doubly(a);
	
	ft_sa(&a);
	lstiter_doubly(a, print_content);
	if (max_arguments < 8)
	{
		ft_printf("Max Argc: %d\n", max_arguments);
		lstiter_doubly(a, print_content);
	}
	
	
	// while(a)
	// {
	// 	ft_printf("%d\n", a->nbr);
	// 	a = a->next;
	// }
	// return(0);
}

// 2 8 7 9 1 3 12

// valid int  check a43
// range von e


// alle ellemente der liste printen 
// 	mit lstiterdb (vorbild lstadd_backdb)
// 	schauen was in stacks drin isst 
// 	- stimmten die list functionen 
	
// 	alle list auf double umformen 
// 	testen 
// 	sortiertfunctionen implementieren (das sa ss, pa functioniert. )
// 	dann sort algo anwenden. 


// make, make fclean