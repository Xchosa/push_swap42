/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/16 12:41:01 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	void 	*content;
	// int		nbr;
	// int		index;
	struct s_stack	*next;
	struct s_stack 	*prev;
}	t_stack;

typedef	struct s_object
{
	int index;
	int nbr;
	int index_sorted;
	
} t_object;

t_object	*init_object(t_object *object, int index, int nbr, int index_sorted);

void	lstadd_back_doubly(t_stack **lst, t_stack *new);
void	lstadd_front_doubly(t_stack **lst, t_stack *new);
void	lstiter_doubly(t_stack *lst, void (*f)(t_object *));
void	lstiter_doubly_index(t_stack *lst, void (*f)(int index));
void	lstclear_doubly(t_stack **lst, void (*del)(void *));
t_stack	*lstlast_doubly(t_stack *lst);
t_stack	*lstnew_doubly(t_object *object);
int		lstsize_doubly(t_stack *lst);


void	ft_swap_2nbr(t_stack**a);
void	ft_swap_only(t_stack **a);

void	ft_swap(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

void	print_content(t_object *content);
void	del(void *content);

void	handle_stack_ab(t_stack **a,t_stack **b);
void	add_index(int index);
#endif