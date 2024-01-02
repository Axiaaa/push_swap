/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:51 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/02 18:12:54 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

long	ft_strtolong(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && sign == 1
				&& (str[i] - '0') > LONG_MAX % 10) || (result == LONG_MAX / 10
				&& sign == -1 && (str[i] - '0') > -(LONG_MIN % 10)))
			exit(EXIT_FAILURE);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	is_alreadry_sorted(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				return ;
			j++;
		}
		i++;
	}
	exit(0);
}

void	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				exit_error();
			j++;
		}
		i++;
	}
}

void	check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || av[i][j] == '-')
			{
				if (ft_strtolong(av[i]) > INT_MAX
					|| ft_strtolong(av[i]) < INT_MIN)
					exit_error();
			}
			else
				exit_error();
			j++;
		}
		i++;
	}
	is_duplicate(av);
	is_alreadry_sorted(av);
}
