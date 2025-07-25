/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:03:30 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 13:54:39 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len); // returns the number of elements in the stack
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
		ft_create_and_validate(&a, numbers, true); // passing numbers
		ft_free_split(numbers); // then freeing
	}
	else
		ft_create_and_validate(&a, argv + 1, false); // passing arguments
	if (!ft_check_if_sorted(a))
		ft_sort(&a, &b, ft_get_len(a)); // calling the sorting algorithm with the size of the stack
	ft_free_stack(&a);
	return (0);
}
