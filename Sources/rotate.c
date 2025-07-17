/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 18:17:43 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || (!(*stack)))
		return ;
	last = ft_find_last(*stack); // we find the last one
	last->next = *stack; // link it to the current head
	*stack = (*stack)->next; // move the head one node forward
	(*stack)->prev = NULL; // now the second node in on the top
	last->next->prev = last; // now the former last node in the second last
	last->next->next = NULL; // now the previous head is the last one
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest) 
		ft_rr(a, b); // while the top of the stack a is not the cheapest node's target and the top of stack b is not the cheapest node
	ft_set_index(a); // recalculating costs
	ft_set_index(b);
}
