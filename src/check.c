/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:09:09 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/10 13:08:28 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	sign_check(int ac, char **av)
{
	int	i;
	int	j;

	i = ac - 1;
	j = 0;
	while (av[i] && i > 0)
	{
		if (ft_strlen(av[i]) == 1 && av[i][0] == '-')
			return (ERROR);
		if (ft_strlen(av[i]) == 1 && av[i][0] == '+')
			return (ERROR);
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ERROR);
			j++;
		}
		j = 0;
		i--;
	}
	return (SUCCESS);
}

static int	dup_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac)
		{
			if (i != j && ft_atoi(av[i]) == ft_atoi(av[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	int_check(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if (size == 0 || ((size > 10 && av[i][0] != '-')
			&& (size > 10 && av[i][0] != '+')) || size > 11)
			return (ERROR);
		if (av[i][0] != '-' && av[i][0] != '+' && size == 10
			&& ft_strncmp(av[i], "2147483647", 10) > 0)
			return (ERROR);
		if (av[i][0] == '-' && size == 11 &&
			ft_strncmp(av[i], "-2147483648", 11) > 0)
			return (ERROR);
		if (av[i][0] == '+' && size == 11 &&
			ft_strncmp(av[i], "+2147483647", 11) > 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	parse(int ac, char **av)
{
	if (ac <= 1)
		exit(ERROR);
	else if (int_check(ac, av) == ERROR || dup_check(ac, av) == ERROR
		|| sign_check(ac, av) == ERROR)
	{
		write (2, "Error\n", 6);
		exit(ERROR);
	}
	return (SUCCESS);
}
