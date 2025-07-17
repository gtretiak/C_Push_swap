/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 14:03:40 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || (!(*stack)))
		return ;
	last = ft_find_last(*stack);  // we find the last one
	last->next = *stack; // and attach it to the front of the stack
	(*stack)->prev = last;
	last->prev->next = NULL; // detaching from the previous position
	last->prev = NULL;
	(*stack) = last; // now it´s the first element
}

void	ft_rra(t_stack **a)
{
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack **b)
{
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
