/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:11 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 14:53:32 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_b_to_a(t_stack **a, t_stack **b)
{
	ft_finish_him(a, (*b)->target, 'a'); // we will rotate a to place on the top the node which is needed node to push on from b to a
	ft_pa(a, b);
}

void	ft_finish_him(t_stack **stack, t_stack *node_to_top, char name)
{
	while (*stack != node_to_top) // while the target node isn´t on the top
	{
		if (name == 'a') // stack determination
		{
			if (node_to_top->above_median) // rotation deirection determination
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else
		{
			if (node_to_top->above_median) // rotation deirection determination
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	ft_set_cheapest(t_stack **stack)
{
	int		price;
	t_stack	*match_node;
	t_stack	*curr;

	if (!stack || !*stack)
		return ;
	price = MAXINT; // starting with INT_MAX
	curr = *stack;
	while (curr) // iterating through the stack
	{
		if (curr->cost < price) // if reassign value of price with the smallest cost
		{
			price = curr->cost;
			match_node = curr;
		}
		curr = curr->next;
	}
	match_node->cheapest = true;
}

void	ft_set_target(t_stack **a, t_stack **b)
{
	t_stack	*curra;
	t_stack	*currb;
	t_stack	*target;
	int		match;

	currb = *b;
	while (currb) // for every node in B we will find the target node in A
	{
		match = MAXINT;
		curra = *a;
		while (curra) // iterating through the stack A, we compare numbers with the current B node
		{
			if (curra->nb > currb->nb && curra->nb < match) // we need the smallest A number, that is bigger than B
			{
				match = curra->nb;
				target = curra;
			}
			curra = curra->next;
		}
		if (match == MAXINT)
			currb->target = ft_find_smallest(*a);
		else
			currb->target = target;
		currb = currb->next;
	}
}

void	ft_get_cost(t_stack **a, t_stack **b)
{
	int		len_a;
	int		len_b;
	t_stack	*curr;

	len_a = ft_get_len(*a);
	len_b = ft_get_len(*b);
	curr = *b;
	while (curr) // iterating through the stack we compute the price for movements
	{
		curr->cost = curr->index; 
		if (!curr->above_median)
			curr->cost = len_b - curr->index;
		if (curr->target->above_median)
			curr->cost += curr->target->index;
		else
			curr->cost += len_a - curr->target->index;
		curr = curr->next;
	}
}
