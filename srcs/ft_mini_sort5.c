/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 08:54:44 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/19 17:17:09 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_op_a(t_pile **pile_a, t_pile **pile_b, t_media *e)
{
	t_pile *tmp_a;

	tmp_a = *pile_a;
	if (tmp_a->pos < (e->max - 1))
		ft_pb(pile_a, pile_b);
	else
		ft_ra(pile_a);
}

static void	ft_op_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp_a;
	t_pile *tmp_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (tmp_b->pos == tmp_a->pos - 1)
		ft_pa(pile_b, pile_a);
	else
		ft_rb(pile_b);
}

void		ft_mini_sort5(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_pile *tmp_a;
	t_pile *tmp_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (!(*pile_b) && ft_is_sort(pile_a, pile_b) == 1)
		return ;
	if (!(*pile_b))
	{
		while (ft_listlen(*pile_a) > 2)
			ft_op_a(pile_a, pile_b, e);
		ft_mini_sort5(pile_a, pile_b, e, medi_b);
		return ;
	}
	if (tmp_a->pos > tmp_a->next->pos)
	{
		ft_swap_mini(pile_a);
		ft_mini_sort5(pile_a, pile_b, e, medi_b);
		return ;
	}
	while (*pile_b)
		ft_op_b(pile_a, pile_b);
	ft_mini_sort5(pile_a, pile_b, e, medi_b);
	return ;
}
