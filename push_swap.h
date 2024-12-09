/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/05 17:35:51 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_llist
{
	void 	*content;
	t_llist	*next;
	t_llist *prev;
}	t_llist;


// typedeff struct s_stacks
// {
// 	t_list *stack_a;
// 	t_list *stack_b;
	
// }	t_stacks;

// typedef struct s_list
// {
// 	int				nbr;
// 	int				push_cost;
// 	bool			above_median;
// 	bool			cheapest;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// 	struct s_list	*target_node;
// }					t_stack_node;

// handle erors
// stack init
// node init
// algo


#endif