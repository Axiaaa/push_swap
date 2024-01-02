/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:23 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:17:28 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_snode **a)
{
	t_snode	*max;

	max = find_max_value(*a);
	if (max == *a)
		ra(a, true);
	else if ((*a)->next == max)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
