/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/24 16:24:23 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || (!(*stack)))
		return ;
	last = ft_find_last(*stack); // we find the last one
	last->next = *stack; // and attach it to the front of the stack
	(*stack)->prev = last;
	last->prev->next = NULL; // detaching from the previous position
	last->prev = NULL; 
	(*stack) = last; // now it´s the first element
}

void	ft_rra(t_stack **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	ft_reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		ft_rrr(a, b); // while the head of the stack a is not the target for cheapest, and stack b’s head is not the cheapest node itself
	ft_set_index(a); // recalculating node indecis after movement to find the cheapest node again
	ft_set_index(b);
}
