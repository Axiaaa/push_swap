/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_set_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:49 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 17:58:28 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_target_b(t_snode *a, t_snode *b)
{
	t_snode	*current_a;
	t_snode	*target;
	long	best_match;

	while (b)
	{
		current_a = a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min_value(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes_b(t_snode *a, t_snode *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
