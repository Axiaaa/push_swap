/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:29:46 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:17:18 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	min_on_top(t_snode **a)
{
	while ((*a)->value != find_min_value(*a)->value)
	{
		if (find_min_value(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	free_stack(t_snode **stack)
{
	t_snode	*tmp;
	t_snode	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	av = NULL;
}

int	main(int ac, char **av)
{
	static t_snode	*a;
	static t_snode	*b;

	av++;
	if (ac < 2)
		exit(1);
	else if (ac == 2)
		av = ft_split(av[0], ' ');
	check(av);
	init_stack(&a, av);
	if (!is_sorted(a))
	{
		if (len(a) == 2)
			sa(&a, true);
		else if (len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
	if (ac == 2)
		free_av(av);
	return (0);
}
