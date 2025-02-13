/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:29:41 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/13 09:23:41 by poverbec         ###   ########.fr       */
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
	if (parse_result)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error \n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	read_commands(&a, &b);
	if (check_order(&a) == true)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_stack(&a);
	return (EXIT_SUCCESS);
}

// Commands entered in the terminal or piped get read, and the stack
// gets manipulated accordingly.
void	read_commands(t_stack **a, t_stack **b)
{
	char	*command;

	command = NULL;
	while (1)
	{
		command = get_next_line(STDIN_FILENO);
		if (!command)
			return ;
		read_and_use_commands(command, a, b);
		free(command);
	}
}

// swaps, pushes, sorts without printing. 
void	read_and_use_commands(char *command, t_stack **a, t_stack **b)
{
	if (ft_strncmp(command, "pb\n", 4) == 0)
		ft_push_pb_b(a, b);
	else if (ft_strncmp(command, "pa\n", 4) == 0)
		ft_push_pa_b(a, b);
	else if (ft_strncmp(command, "ra\n", 4) == 0)
		ft_rotate_ra_b(a);
	else if (ft_strncmp(command, "rb\n", 4) == 0)
		ft_rotate_rb_b(b);
	else if (ft_strncmp(command, "sa\n", 4) == 0)
		ft_swap_sa_b(a);
	else if (ft_strncmp(command, "sb\n", 4) == 0)
		ft_swap_sb_b(b);
	else if (ft_strncmp(command, "ss\n", 4) == 0)
		ft_swap_ss_b(a, b);
	else if (ft_strncmp(command, "rra\n", 5) == 0)
		ft_rotate_rra_b(a);
	else if (ft_strncmp(command, "rrb\n", 5) == 0)
		ft_rotate_rrb_b(b);
	else if (ft_strncmp(command, "rrr\n", 5) == 0)
		ft_rotate_rrr_b(a, b);
	else if (ft_strncmp(command, "rr\n", 4) == 0)
		ft_rotate_rr_b(a, b);
	else
		exit(ft_printf("Error\n", STDERR_FILENO));
}
