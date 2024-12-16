/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 15:30:34 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// void push functionen implementieren 
// das die swap push functionen im handler functionieren
// sortieren lassen, durchz'hlen in index_sorted und dann nach dem index_sorted sortieren

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_object *object; 

	a = NULL;
	b = NULL;
	if((argc == 1) || (argc == 2 && !argv[1][0] ))
		return (0);
	int i;
	i = 1;
	
	t_stack *node;
	int max_arguments;
	
	while(i< argc )
	{
		object = malloc (sizeof(t_object));
		if(!object)
			return (lstclear_doubly(&a, del), 1);
		node = lstnew_doubly(init_object(object, i, ft_atoi(argv[i]), 0));// initailisere index_sorted mit 0
		if(!node)
			return(lstclear_doubly(&a, del), 1);
		lstadd_back_doubly(&a,node);
		i++;
	}
	if(argc == 3)
			return(ft_swap_2nbr(&a),0);
	//Tests
	lstiter_doubly(a, print_content);
	max_arguments = lstsize_doubly(a);
	// handle_stack_ab(&a, &b);
	
	ft_sa(&a);
	lstiter_doubly(a, print_content);
	ft_pa(&a, &b);
	lstiter_doubly(b, print_content);
	if (max_arguments > 10)
	{
		ft_printf("Max Argc: %d\n", max_arguments);
		lstiter_doubly(a, print_content);
	}
}

// alle ellemente der liste printen 
// 	mit lstiterdb (vorbild lstadd_backdb)
// 	schauen was in stacks drin isst 
// 	- stimmten die list functionen 
	
// 	alle list auf double umformen 
// 	testen 
// 	sortiertfunctionen implementieren (das sa ss, pa functioniert. )
// 	dann sort algo anwenden. 


// make, make fclean

// void push functionen implementieren 