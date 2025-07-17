/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 14:03:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*target;

	if (!src || !(*src)) // there´s nothing to push
		return ;
	target = *src; // storing the current top node in the target node
	if ((*src)->next) // if the src stack has more than one node, we move the head pointer to the next node
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	else // otherwise just setting the stack to NULL (empty)
		*src = NULL;
	if (*dest) // if the dest stack is not empty, we link the target node in front of the current dest head
	{
		(*dest)->prev = target;
		target->next = *dest;
		target->prev = NULL;
		*dest = target;
	}
	else // otherwise we just make the target the new dest head
	{
		*dest = target;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{ // moving from b to a
	if (!b || !(*b))
		return ;
	ft_push(b, a);
}

void	ft_pb(t_stack **a, t_stack **b)
{ // moving from a to b
	if (!a || !(*a))
		return ;
	ft_push(a, b);
}
