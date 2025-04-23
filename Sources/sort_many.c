/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:16:33 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 13:16:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_nodes(t_stack **a, t_stack **b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target(a, b);
	ft_get_cost(a, b);
	ft_set_cheapest(b);
}

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	int		smallest;

	if (!stack)
		return (NULL);
	smallest = MAXINT;
	while (stack)
	{
		if (stack->nb < smallest)
		{
			smallest = stack->nb;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*ft_return_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_set_index(t_stack **stack)
{
	int		i;
	int		median;
	t_stack	*curr;

	i = 0;
	if (!stack)
		return ;
	median = ft_get_len(*stack) / 2;
	curr = *stack;
	while (curr)
	{
		curr->index = i;
		if (i <= median)
			curr->above_median = true;
		else
			curr->above_median = false;
		curr = curr->next;
		i++;
	}
}

void	ft_sort_many(t_stack **a, t_stack **b, int len)
{
	t_stack	*smallest;

	if (!ft_check_if_sorted(*a))
		ft_pb(a, b);
	if (!ft_check_if_sorted(*a))
		ft_pb(a, b);
	while (len-- > 3 && !ft_check_if_sorted(*a))
		ft_smart_pb(a, b);
	if (!ft_check_if_sorted(*a))
		ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes(a, b);
		ft_move_b_to_a(a, b);
	}
	ft_set_index(a);
	smallest = ft_find_smallest(*a);
	if (smallest->above_median)
	{
		while (*a != smallest)
			ft_ra(a);
	}
	else
		while (*a != smallest)
			ft_rra(a);
}
