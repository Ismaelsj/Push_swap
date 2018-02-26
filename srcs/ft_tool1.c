/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 09:58:10 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/23 16:13:04 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_bla(char *entier, int j)
{
	if (entier[j] == '-' || entier[j] == '+')
		j++;
	while (ft_isdigit(entier[j]) == 1)
		j++;
	return (j);
}

int				ft_put_in(char *entier, t_pile **begin_list, int j)
{
	t_pile	*tmp;

	tmp = *begin_list;
	while (entier[j])
	{
		if (ft_isdigit(entier[j]) == 1 || ((entier[j] == '+'
				|| entier[j] == '-') && ft_isdigit(entier[j + 1]) == 1))
		{
			if (tmp)
			{
				tmp->next = ft_newpile(ft_atol(entier + j));
				tmp = tmp->next;
			}
			else
			{
				tmp = ft_newpile(ft_atol(entier + j));
				*begin_list = tmp;
			}
			j = ft_bla(entier, j);
		}
		else
			j++;
	}
	return (1);
}

int				ft_get_list(char **entier, int argc, t_pile **begin_list)
{
	int		i;
	t_pile	*tmp;

	i = 1;
	while (!(*begin_list) && i < argc)
	{
		if (ft_put_in(entier[i], begin_list, 0) == 0)
			return (0);
		i++;
	}
	tmp = *begin_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (i < argc)
	{
		if (ft_put_in(entier[i], &tmp, 0) == 0)
			return (0);
		while (tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (1);
}

int				ft_is_sort(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp1;
	t_pile *tmp2;

	if (*pile_b)
		return (0);
	tmp1 = *pile_a;
	tmp2 = *pile_a;
	while (tmp1)
	{
		if (tmp2->nb > tmp1->nb)
			return (0);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	return (1);
}

int				ft_listlen(t_pile *pile_a)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
