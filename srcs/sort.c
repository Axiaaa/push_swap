/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:26 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:07:22 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_b_to_a(t_snode **a, t_snode **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, true);
}

void	move_a_to_b(t_snode **a, t_snode **b)
{
	t_snode	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		reverse_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(b, a, true);
}

void	rotate_both(t_snode **a, t_snode **b, t_snode *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_snode **a, t_snode **b, t_snode *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	sort(t_snode **a, t_snode **b)
{
	int	len_a;

	len_a = len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
