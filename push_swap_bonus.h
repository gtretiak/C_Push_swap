/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:02:48 by gtretiak          #+#    #+#             */
/*   Updated: 2025/06/14 17:08:26 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "C_libft/libft.h"

# ifndef MAXINT
#  define MAXINT 2147483647
# endif

# ifndef MININT
#  define MININT -2147483648
# endif

typedef struct s_stack
{
	struct s_stack		*target;
	struct s_stack		*prev;
	struct s_stack		*next;
	int					nb;
}	t_stack;

long	ft_atol(const char *str);
int		ft_check_if_sorted(t_stack *a);
void	ft_create_and_validate(t_stack **a, char **numbers, bool marg);
int		ft_check_syntax(char *str);
int		ft_check_dup(t_stack *a, int n);
void	ft_append_node(t_stack **a, int n);
t_stack	*ft_find_last(t_stack *head);

void	ft_free_split(char **arr);
void	ft_free_errors(t_stack **a, char **numbers, bool marg);
void	ft_free_stack(t_stack **a);

void	ft_reading(t_stack **a, t_stack **b);
int		ft_execute(t_stack **a, t_stack **b, char *cmd);

void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
