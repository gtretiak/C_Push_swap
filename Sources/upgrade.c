/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:28:35 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 13:59:12 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smart_pb(t_stack **a, t_stack **b) 
{ // calculating indexes, rotation direction, targets, costs, cheapests
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_biggest(a, b); 
	ft_get_cost_a(a, b);
	ft_set_cheapest(a);
	ft_move_a_to_b(a, b);
}

void	ft_move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_return_cheapest(*a);
	if (cheapest->above_median
		&& cheapest->target->above_median) // if the nodes in both stacks are above median
		ft_rotate_both(b, a, cheapest); 
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median)) // if the nodes in both stacks are below median
		ft_reverse_rotate_both(b, a, cheapest);
	ft_finish_him(a, cheapest, 'a'); // separately A with the cheapest
	ft_finish_him(b, cheapest->target, 'b'); // separately B with the target of the cheapest
	ft_pb(a, b);
}

void	ft_set_target_biggest(t_stack **a, t_stack **b)
{
	t_stack	*curra;
	t_stack	*currb;
	t_stack	*target;
	int		match;

	curra = *a;
	while (curra) // for every node in A
	{
		match = MININT; // starting with INT_MIN
		currb = *b;
		while (currb) // iterating through the stack B
		{
			if (currb->nb < curra->nb && currb->nb > match) // we try find the biggest number in B, that is smaller than current number in A
			{
				match = currb->nb;
				target = currb;
			}
			currb = currb->next;
		}
		if (match == MININT) // that means we didn´t find it, so let´s take the biggest one
			curra->target = ft_find_biggest(*b);
		else
			curra->target = target;
		curra = curra->next;
	}
}

void	ft_get_cost_a(t_stack **a, t_stack **b) // logic similar to get_cost, but this time it calculates costs to push from A to B
{
	int		len_a;
	int		len_b;
	t_stack	*curr;

	len_a = ft_get_len(*a);
	len_b = ft_get_len(*b);
	curr = *a;
	while (curr)
	{
		curr->cost = curr->index;
		if (!curr->above_median)
			curr->cost = len_a - curr->index;
		if (curr->target->above_median)
			curr->cost += curr->target->index;
		else
			curr->cost += len_b - curr->target->index;
		curr = curr->next;
	}
}
