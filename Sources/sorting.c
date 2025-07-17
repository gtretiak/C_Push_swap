/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:07:46 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/07 12:27:54 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nb > a->next->nb) // the rule for sorting
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*ft_find_biggest(t_stack *stack)
{
	t_stack	*biggest_node;
	int		biggest;

	if (!stack)
		return (NULL);
	biggest = MININT; // starting from INT_MIN
	while (stack)
	{
		if (stack->nb > biggest) // we reassign the value of biggest
		{
			biggest = stack->nb;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = ft_find_biggest(*a);
	if (biggest == *a) // with first two if/else if ew make sure that the biggest is on the bottom
		ft_ra(a);
	else if (biggest == (*a)->next)
		ft_rra(a);
	if ((*a)->nb > (*a)->next->nb) // then we swap first two if needed
		ft_sa(a);
}

void	ft_sort_five(t_stack **a, t_stack **b, int len) // actually for 4 and 5 elements
{
	while (len-- > 3)
	{
		ft_init_nodes(a, b);
		ft_finish_him(a, ft_find_smallest(*a), 'a'); // we push two smallest to the stack B
		ft_pb(a, b);
	}
	ft_sort_three(a);
	ft_pa(a, b); // this is for 4th element
	if (*a)
		ft_pa(a, b); // this is for 5th element
}

void	ft_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 2) // we know here that the stack isn´t sorted, so we apply "swap"
		ft_sa(a);
	else if (len == 3)
		ft_sort_three(a);
	else if (len == 4 || len == 5)
		ft_sort_five(a, b, len);
	else
		ft_sort_many(a, b, len);
}
