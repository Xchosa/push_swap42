/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:47:34 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/04 16:47:58 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		parse_result;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	parse_result = start_parse(argc, argv, &a);
	if (parse_result == EXIT_FAILURE)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if ((check_order(&a) == 1 || lstsize_ps(a) == 1))
	{
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	chose_sorting(&a, &b);
	free_stack(&a);
	return (EXIT_SUCCESS);
}
