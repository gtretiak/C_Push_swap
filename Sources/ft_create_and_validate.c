/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_validate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:09:20 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 14:16:45 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_check_syntax(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 43 || str[i] == 45))
			return (1);
		else if (str[i] == 43 || str[i] == 45)
		{
			if (sign > 0 || !(str[i + 1] >= '0' && str[i + 1] <= '9')
				|| (i > 0 && str[i - 1] != 32))
				return (1);
			sign++;
		}
		i++;
	}
	return (0);
}

t_stack	*ft_find_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_append_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	node->cheapest = false;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_find_last(*a);
		last->next = node;
		node->prev = last;
	}
}

void	ft_create_and_validate(t_stack **a, char **numbers, bool marg)
{
	long	n;
	int		i;

	i = 0;
	while (numbers[i])
	{
		if (ft_check_syntax(numbers[i]))
			ft_free_errors(a, numbers, marg);
		n = ft_atol(numbers[i]);
		if (n > MAXINT || n < MININT)
			ft_free_errors(a, numbers, marg);
		if (ft_check_dup(*a, (int)n))
			ft_free_errors(a, numbers, marg);
		ft_append_node(a, (int)n);
		i++;
	}
}
