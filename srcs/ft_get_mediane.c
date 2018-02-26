/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:07:55 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/22 17:03:36 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mediane_b(t_pile **pile_b, t_media *e, t_media_b **medi_b)
{
	if ((ft_listlen(*pile_b) + e->pushed) % 2 != 0)
		e->media_b = ((ft_get_e_max(*pile_b) + e->pushed + 1) / 2);
	else
		e->media_b = ((ft_get_e_max(*pile_b) + e->pushed) / 2);
	ft_get_mediane_b(medi_b, e->media_b);
}

void	ft_mediane_a(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_media_b *tmp;

	tmp = *medi_b;
	if (*medi_b)
	{
		e->media_a = tmp->medi;
		if (e->pushed >= tmp->medi - 1)
			ft_del_maillon(medi_b);
		if (tmp->medi <= e->pushed)
			ft_quicksort(pile_a, pile_b, e, medi_b);
	}
	else
	{
		if ((e->max + e->pushed) % 2 != 0)
			e->media_a = (e->max + e->pushed + 1) / 2;
		else
			e->media_a = (e->max + e->pushed) / 2;
		ft_get_mediane_b(medi_b, e->media_a);
	}
}
