/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:34:42 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/17 13:39:09 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tab(t_pile *pile_a, int *str)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	while (i < ft_listlen(pile_a))
	{
		j = i;
		while (j < ft_listlen(pile_a))
		{
			if (str[i] > str[j])
			{
				a = str[i];
				str[i] = str[j];
				str[j] = a;
			}
			j++;
		}
		i++;
	}
}
