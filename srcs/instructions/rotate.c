/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:43 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 17:58:37 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_snode **s)
{
	t_snode	*last;

	if (!*s || !(*s)->next)
		return ;
	last = findlastnode(*s);
	last->next = *s;
	*s = (*s)->next;
	(*s)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ra(t_snode **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_snode **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_snode **a, t_snode **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
