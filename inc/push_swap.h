/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:29:06 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 17:59:25 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_snode
{
	int				value;
	int				position;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_snode	*target;
	struct s_snode	*next;
	struct s_snode	*previous;
}					t_snode;

t_snode				*find_min_value(t_snode *s);
t_snode				*find_max_value(t_snode *s);
t_snode				*get_cheapest(t_snode *s);
t_snode				*findlastnode(t_snode *s);

size_t				len(t_snode *s);

bool				is_sorted(t_snode *s);

void				reverse_rotate_both(t_snode **a, t_snode **b,
						t_snode *cheapest);
void				prep_for_push(t_snode **s, t_snode *top, char stack_name);
void				rotate_both(t_snode **a, t_snode **b, t_snode *cheapest);
void				init_stack(t_snode **stack, char **argv);
void				add_to_stack(t_snode **stack, int value);
void				cost_analysis_a(t_snode *a, t_snode *b);
void				move_b_to_a(t_snode **a, t_snode **b);
void				move_a_to_b(t_snode **a, t_snode **b);
void				init_nodes_b(t_snode *a, t_snode *b);
void				init_nodes_a(t_snode *a, t_snode *b);
void				set_target_b(t_snode *a, t_snode *b);
void				set_target_a(t_snode *a, t_snode *b);
void				sort(t_snode **a, t_snode **b);
void				is_alreadry_sorted(char **av);
long				ft_strtolong(const char *str);
void				current_index(t_snode *node);
void				set_cheapest(t_snode *a);
void				min_on_top(t_snode **a);
void				sort_three(t_snode **a);
void				swap(t_snode **firstnode);
void				is_duplicate(char **av);
void				check(char **av);
void				exit_error(void);
void				sa(t_snode **a, bool print);
void				sb(t_snode **b, bool print);
void				ss(t_snode **a, t_snode **b, bool print);
void				rb(t_snode **b, bool print);
void				ra(t_snode **a, bool print);
void				rotate(t_snode **s);
void				reverse_rotate(t_snode **s);
void				rra(t_snode **a, bool print);
void				rrb(t_snode **b, bool print);
void				rrr(t_snode **a, t_snode **b, bool print);
void				pb(t_snode **a, t_snode **b, bool print);
void				pa(t_snode **a, t_snode **b, bool print);
void				push(t_snode **dst, t_snode **src);
void				rr(t_snode **a, t_snode **b, bool print);

#endif