/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 14:03:26 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || (!(*stack)))
		return ;
	last = ft_find_last(*stack);  // we find the last one
	last->next = *stack; // link it to the current head
	*stack = (*stack)->next; // move the head one node forward
	(*stack)->prev = NULL; // now the second node in on the top
	last->next->prev = last; // now the former last node in the second last
	last->next->next = NULL; // now the previous head is the last one
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
