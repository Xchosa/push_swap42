/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/11 14:23:22 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	void 	*content;
	int		nbr;
	struct s_stack	*next;
	struct s_stack 	*prev;
}	t_stack;

void	lstadd_back_doubly(t_stack **lst, t_stack *new);
void	lstadd_front_doubly(t_stack **lst, t_stack *new);
void	lstiter_doubly(t_stack *lst, void (*f)(int nbr));
void	lstclear_doubly(t_stack **lst, void (*del)(void *));
t_stack	lstlast_doulby(t_stack *lst);
t_stack	*lstnew_doubly(int nbr);

void	ft_sa(t_stack **a);


#endif