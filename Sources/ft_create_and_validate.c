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
		if (a->nb == n) // if any number in the stack is equal to a certain number
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
	if (str[i] == '\0') // empty string -> invalid
		return (1);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 43 || str[i] == 45))
			return (1); // not a digit or a sign
		else if (str[i] == 43 || str[i] == 45)
		{
			if (sign > 0 || !(str[i + 1] >= '0' && str[i + 1] <= '9')
				|| (i > 0 && str[i - 1] != 32)) // if it´s not the begining of the string, then previous char should be space
				return (1); // if the sign has already appeared and the next char (after a sign) is a digit
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
	if (!(*a)) // if the stack is empty yet, then the node is the first one
	{
		*a = node;
		node->prev = NULL;
	}
	else // otherwise appending to the tail
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
	while (numbers[i]) // iterating through all the strings-numbers
	{
		if (ft_check_syntax(numbers[i])) // if syntax is invalid
			ft_free_errors(a, numbers, marg);
		n = ft_atol(numbers[i]);
		if (n > MAXINT || n < MININT) // if it´s integer overflow case
			ft_free_errors(a, numbers, marg);
		if (ft_check_dup(*a, (int)n)) // or if there´s a duplicate number
			ft_free_errors(a, numbers, marg);
		ft_append_node(a, (int)n);
		i++;
	}
}
