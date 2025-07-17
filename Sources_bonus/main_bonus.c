/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:03:30 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/09 15:35:41 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	n;
	short	s;

	i = 0;
	n = 0;
	s = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n = n + str[i] - '0';
		i++;
	}
	if (s > 0)
		n = -n;
	return (n);
}

int	ft_execute(t_stack **a, t_stack **b, char *cmd)
{ // actual executing based on the given cmd
	if (!ft_strncmp(cmd, "ra\n", 3))
		ft_ra(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		ft_rb(b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		ft_rr(a, b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		ft_rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		ft_rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		ft_rrr(a, b);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		ft_sa(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		ft_sb(b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ft_ss(a, b);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		ft_pa(a, b);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		ft_pb(a, b);
	else
		return (1);
	return (0);
}

int	ft_check_if_sorted(t_stack *a) // in ascending order
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nb > a->next->nb) // oif any number is greater than the next -> not sorted
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_reading(t_stack **a, t_stack **b)
{
	char	*cmd;
	int		status;

	while (1) // endless loop for reading commands
	{
		cmd = get_next_line(0, 1);
		if (cmd == NULL) // CTRL+D
			break ;
		status = ft_execute(a, b, cmd);
		free(cmd);
		if (status) // 1 means invalid cmd
		{
			ft_free_stack(b);
			ft_free_errors(a, NULL, false);
		}
	}
	if (ft_check_if_sorted(*a) && !*b) // Here we check if the stack a is sorted and the stack b is empty
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (b || *b)
		ft_free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a; // input stack
	t_stack	*b; // auxiliary stack used for sorting
	char	**numbers; // array of strings in case of quoted input like "1 234 5687 984"

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (1);
		ft_create_and_validate(&a, numbers, true);  // passing numbers
		ft_free_split(numbers); // then freeing
	}
	else
		ft_create_and_validate(&a, argv + 1, false); // passing arguments
	ft_reading(&a, &b);
	ft_free_stack(&a);
	return (0);
}
