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
		if (a->nb > a->next->nb)
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
	biggest = MININT;
	while (stack)
	{
		if (stack->nb > biggest)
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
	if (biggest == *a)
		ft_ra(a);
	else if (biggest == (*a)->next)
		ft_rra(a);
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a);
}

void	ft_sort_five(t_stack **a, t_stack **b, int len)
{
	while (len-- > 3)
	{
		ft_init_nodes(a, b);
		ft_finish_him(a, ft_find_smallest(*a), 'a');
		ft_pb(a, b);
	}
	ft_sort_three(a);
	ft_pa(a, b);
	if (*a) //TODO
		ft_pa(a, b);
}

void	ft_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		ft_sa(a);
	else if (len == 3)
		ft_sort_three(a);
	else if (len == 4 || len == 5)
		ft_sort_five(a, b, len);
	else
		ft_sort_many(a, b, len);
}
