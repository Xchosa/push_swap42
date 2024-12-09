/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:44:40 by poverbec          #+#    #+#             */
/*   Updated: 2024/12/09 17:28:47 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	void 	*content;
	int		nbr;
	struct s_stack	*next;
	struct s_stack 	*prev;
}	t_stack;

void	ft_llstadd_back(t_stack **lst, t_stack *new);
void	ft_llstadd_front(t_stack **lst, t_stack *new);
void	ft_llstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_llstlast(t_stack *lst);
t_stack	*ft_llstnew(int nbr);




#endif