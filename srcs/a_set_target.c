/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_set_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:45 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:04:43 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	current_index(t_snode *node)
{
	int	index;
	int	median;

	index = 0;
	if (!node)
		return ;
	median = len(node) / 2;
	while (node)
	{
		node->position = index;
		if (index <= median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		index++;
	}
}

void	set_target_a(t_snode *a, t_snode *b)
{
	t_snode	*current_b;
	t_snode	*target;
	long	best_match;

	while (a)
	{
		current_b = b;
		best_match = LONG_MIN;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match)
			{
				best_match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max_value(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost_analysis_a(t_snode *a, t_snode *b)
{
	int	len_a;
	int	len_b;

	len_a = len(a);
	len_b = len(b);
	while (a)
	{
		a->push_cost = a->position;
		if (!(a->above_median))
			a->push_cost = len_a - (a->position);
		if (a->target->above_median)
			a->push_cost += a->target->position;
		else
			a->push_cost += len_b - (a->target->position);
		a = a->next;
	}
}

void	set_cheapest(t_snode *a)
{
	long	cheapest_val;
	t_snode	*cheapest_node;

	if (!a)
		return ;
	cheapest_val = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_val)
		{
			cheapest_val = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_snode *a, t_snode *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
