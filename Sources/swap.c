/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/24 16:30:45 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ; // if stack is NULL, empty or has just one node
	first = *stack;
	second = first->next;
	*stack = second;
	first->next = second->next; // now the first points to the third node (or NULL)
	if (first->next) // there´s the third node
		first->next->prev = first; // so let it point to the first
	second->next = first; // new head
	first->prev = second;
	second->prev = NULL; // new head
}

void	ft_sa(t_stack **a)
{
	ft_swap(a);
	if ((*a)->next) // only if there are at least two nodes
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
	if ((*b)->next) // only if there are at least two nodes
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if ((*a)->next && (*b)->next)
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
}
