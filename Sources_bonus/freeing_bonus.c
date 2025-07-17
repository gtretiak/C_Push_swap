/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:57:17 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 14:02:32 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_errors(t_stack **a, char **numbers, bool marg)
{
	if (marg == true) // marg stands for multiple args that were given as one string
		ft_free_split(numbers);
	if (a)
		ft_free_stack(a);
	write(2, "Error\n", 6);
	exit (2);
}

void	ft_free_split(char **arr)
{
	int	i;
	int	l;

	i = 0;
	l = 1;
	if (!arr[0])
		l = 0;
	while (arr[l])
		l++;
	while (i <= l)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}
