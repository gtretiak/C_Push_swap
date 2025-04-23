/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:02:48 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/02 14:40:43 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "Libft/libft.h"

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
	bool				cheapest;
	bool				above_median;
	int					nb;
	int					index;
	int					cost;
}	t_stack;

long	ft_atol(const char *str);
int		ft_check_if_sorted(t_stack *a);
void	ft_create_and_validate(t_stack **a, char **numbers, bool marg);
int		ft_check_syntax(char *str);
int		ft_check_dup(t_stack *a, int n);
void	ft_append_node(t_stack **a, int n);

void	ft_free_split(char **arr);
void	ft_free_errors(t_stack **a, char **numbers, bool marg);
void	ft_free_stack(t_stack **a);

int		ft_get_len(t_stack *stack);
void	ft_sort(t_stack **a, t_stack **b, int len);
void	ft_sort_three(t_stack **a);
void	ft_sort_five(t_stack **a, t_stack **b, int len);
void	ft_sort_many(t_stack **a, t_stack **b, int len);

void	ft_smart_pb(t_stack **a, t_stack **b);
void	ft_init_nodes(t_stack **a, t_stack **b);
void	ft_set_index(t_stack **stack);
void	ft_set_target_biggest(t_stack **a, t_stack **b);
void	ft_set_target(t_stack **a, t_stack **b);
void	ft_get_cost_a(t_stack **a, t_stack **b);
void	ft_get_cost(t_stack **a, t_stack **b);
void	ft_set_cheapest(t_stack **b);

t_stack	*ft_find_last(t_stack *head);
t_stack	*ft_find_smallest(t_stack *stack);
t_stack	*ft_find_biggest(t_stack *stack);
t_stack	*ft_return_cheapest(t_stack *stack);

void	ft_move_a_to_b(t_stack **a, t_stack **b);
void	ft_move_b_to_a(t_stack **a, t_stack **b);
void	ft_finish_him(t_stack **stack, t_stack *node_to_top, char name);

void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

#endif
