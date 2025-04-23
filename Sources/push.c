/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:40:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/24 16:40:30 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*target;

	if (!src || !(*src))
		return ;
	target = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	else
		*src = NULL;
	if (*dest)
	{
		(*dest)->prev = target;
		target->next = *dest;
		target->prev = NULL;
		*dest = target;
	}
	else
	{
		*dest = target;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	if (!a || !(*a))
		return ;
	ft_push(a, b);
	write(1, "pb\n", 3);
}
