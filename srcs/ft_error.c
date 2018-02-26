/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:08:48 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/23 16:31:11 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_set_error(void)
{
	ft_printf("Error\n");
	exit(0);
	return (0);
}

static int	ft_bla(char **entier, int i, int j)
{
	if (ft_atol(entier[i] + j) > 2147483647
			|| ft_atol(entier[i] + j) < -2147483648)
		return (ft_set_error());
	if (entier[i][j] == '+' || entier[i][j] == '-')
		j++;
	while (ft_isdigit(entier[i][j]) == 1)
		j++;
	return (j);
}

int			ft_error(char **entier)
{
	int	i;
	int	j;

	i = 1;
	while (entier[i])
	{
		j = 0;
		while (entier[i][j])
		{
			if (ft_isdigit(entier[i][j]) == 1 || ((entier[i][j] == '+'
						|| entier[i][j] == '-')
						&& ft_isdigit(entier[i][j + 1]) == 1))
				j = ft_bla(entier, i, j);
			else if (entier[i][j] == ' ')
				j++;
			else
				return (ft_set_error());
		}
		i++;
	}
	return (0);
}
