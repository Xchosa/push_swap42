/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2025/01/09 14:42:49 by poverbec         ###   ########.fr       */
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
	int			data;
	int			index;
	int			push_cost;
	int			above_median;
	char		name;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;


int		start_parse(int argc, char **argv, t_stack**a);



void	ft_swap_2nbr(t_stack**a);
void	ft_swap_only(t_stack **a);

void	ft_swap(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

void	ft_push(t_stack **a, t_stack **b);
void 	ft_pb(t_stack **a, t_stack **b);


void	print_content(t_object *content);
void	del(void *content);

void	handle_stack_ab(t_stack **a,t_stack **b);
void	add_index(int index);
#endif