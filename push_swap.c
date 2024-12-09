/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:48:22 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:31:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void print_content(int nbr)
{
	ft_printf("%d\n", nbr);
}
void del(void *content)
{
	free(content);
}

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
	while(i < argc )
	{
		node = lstnew_doubly(ft_atoi(argv[i]));//schreib eine neue node mit einer zahl (*nbr)
		if(!node)
			return(lstclear_doubly(&a, del), 1);
		lstadd_back_doubly(&a,node);//schreibt hinten rein immer eine neue node , 
		// mit einer neuen zahl in den struct, (struct is 28 bit big)
		i++;
	}
	lstiter_doubly(a, print_content);

//if max argc < 100 
	lstclear_doubly(&a, del);
	return(0);
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