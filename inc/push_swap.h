/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/17 11:32:12 by poverbec         ###   ########.fr       */
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

// exclude later
#include <stdio.h>

typedef struct s_stack
{
	long		data;
	int			index;
	int			push_cost;
	int			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;


// parse_nbr
int		start_parse(int argc, char **argv, t_stack**a);
int		parse_input(char **data, t_stack **a);
int 	parse_data_multiple_arg(char **argv, t_stack **a );

// sorting
// void	sort(t_stack **a, t_stack **b);
// bool	check_order(t_stack *a);


// list_push_swap
void	lstadd_back_ps(t_stack **lst, t_stack *new);
void	lstadd_front_ps(t_stack **lst, t_stack *new);
void	lstiter_ps(t_stack *lst, void (*f)(t_stack *));
void	lstclear_ps(t_stack **lst, void (*del)(void *));
t_stack	*lstlast_ps(t_stack *lst);
t_stack	*lstnew_ps(int content);
int		lstsize_ps(t_stack *lst);

// void	ft_swap_2nbr(t_stack**a);
// void	ft_swap_only(t_stack **a);

// void	ft_swap(t_stack **a);
// void	ft_sa(t_stack **a);
// void	ft_sb(t_stack **b);
// void	ft_ss(t_stack **a, t_stack **b);

void	ft_push_b(t_stack **b, t_stack **a);
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_rotate_ra (t_stack **a);

void	put_index(t_stack **a);
// void	ft_push(t_stack **a, t_stack **b);
// void 	ft_pb(t_stack **a, t_stack **b);


void	print_content(t_stack *data);
// void	del(void *data);


#endif