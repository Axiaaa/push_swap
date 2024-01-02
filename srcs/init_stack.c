/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:58 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:16:52 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_to_stack(t_snode **stack, int value)
{
	t_snode	*node;
	t_snode	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_snode));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (!(*stack))
	{
		node->previous = NULL;
		*stack = node;
	}
	else
	{
		last_node = findlastnode(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	prep_for_push(t_snode **s, t_snode *top, char stack_name)
{
	while (*s != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(s, true);
			else
				rra(s, true);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(s, true);
			else
				rrb(s, true);
		}
	}
}

t_snode	*get_cheapest(t_snode *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	init_stack(t_snode **stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		add_to_stack(stack, (int)ft_strtolong(argv[i]));
		i++;
	}
}
