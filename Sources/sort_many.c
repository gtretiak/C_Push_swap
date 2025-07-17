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
	ft_set_index(a); // assigning index values to each node
	ft_set_index(b);
	ft_set_target(a, b); // identifying the best node in A to insert for each node in B 
	ft_get_cost(a, b); // move nodes computation for each B node
	ft_set_cheapest(b); // setting the cheapest node in B for moving
}

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	int		smallest;

	if (!stack)
		return (NULL);
	smallest = MAXINT; // starting with INT_MAX
	while (stack) // iterating through stack
	{
		if (stack->nb < smallest) // reassigning smallest
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
	while (stack) // iterating through stack
	{
		if (stack->cheapest) // if stack->cheapest == "true" is found
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
	{ // depending on the index, we determine which rotation direction is optimal
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
// first we push two elements in the stack b
	if (!ft_check_if_sorted(*a))
		ft_pb(a, b);
	if (!ft_check_if_sorted(*a))
		ft_pb(a, b);
	while (len-- > 3 && !ft_check_if_sorted(*a)) // until we have three elements in A, we push number to B
		ft_smart_pb(a, b); // refined way to push numbers to stack b
	if (!ft_check_if_sorted(*a))
		ft_sort_three(a); // dedicated small-sorting algorithm
	while (*b) // until we have something in B
	{
		ft_init_nodes(a, b); // we recalculate indexes, rotation directions, targets, costs, and cheapests
		ft_move_b_to_a(a, b); // we make a movement
	}
	ft_set_index(a); // atthis point there´s nothing left in B, but even though numbers in A are in order, we might have the smallest number not on the top
	smallest = ft_find_smallest(*a); // we find it
	if (smallest->above_median) // determine rotation direction and rotate
	{
		while (*a != smallest)
			ft_ra(a);
	}
	else
		while (*a != smallest)
			ft_rra(a);
}
