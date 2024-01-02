/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:40 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:07:34 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_snode **firstnode)
{
	if (!*firstnode || !(*firstnode)->next)
		return ;
	*firstnode = (*firstnode)->next;
	(*firstnode)->previous->previous = *firstnode;
	(*firstnode)->previous->next = (*firstnode)->next;
	if ((*firstnode)->next)
		(*firstnode)->next->previous = (*firstnode)->previous;
	(*firstnode)->next = (*firstnode)->previous;
	(*firstnode)->previous = NULL;
}

void	sa(t_snode **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_snode **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_snode **a, t_snode **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
