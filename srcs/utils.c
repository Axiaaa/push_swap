/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:29 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:04:58 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	len(t_snode *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s)
	{
		len++;
		s = s->next;
	}
	return (len);
}

t_snode	*findlastnode(t_snode *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

bool	is_sorted(t_snode *s)
{
	if (!s)
		return (true);
	while (s->next)
	{
		if (s->value > s->next->value)
			return (false);
		s = s->next;
	}
	return (true);
}

t_snode	*find_min_value(t_snode *s)
{
	long	min;
	t_snode	*min_node;

	if (!s)
		return (NULL);
	min = LONG_MAX;
	while (s)
	{
		if (s->value < min)
		{
			min = s->value;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}

t_snode	*find_max_value(t_snode *s)
{
	long		max;
	t_snode		*max_node;

	if (!s)
		return (NULL);
	max = LONG_MIN;
	while (s)
	{
		if (s->value > max)
		{
			max = s->value;
			max_node = s;
		}
		s = s->next;
	}
	return (max_node);
}
