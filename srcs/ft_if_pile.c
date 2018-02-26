/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:58:05 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/23 09:47:37 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_if_pile_b(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_pile *tmp_a;
	t_pile *tmp_b;

	ft_mediane_b(pile_b, e, medi_b);
	while (*pile_b && (ft_listlen(*pile_b) + e->pushed) > e->media_b - 1)
	{
		tmp_a = *pile_a;
		tmp_b = *pile_b;
		if (ft_listlen(*pile_b) <= 15)
		{
			ft_selection_sort(pile_a, pile_b);
			ft_quicksort(pile_a, pile_b, e, medi_b);
			return ;
		}
		if (ft_listlen(*pile_b) == 1)
			ft_pa(pile_b, pile_a);
		else if (tmp_b && tmp_b->pos >= e->media_b)
			ft_pa(pile_b, pile_a);
		else if (ft_last_list(*pile_b) >= e->media_b)
			ft_rrb_pa(pile_b, pile_a);
		else
			ft_rb(pile_b);
	}
	ft_quicksort(pile_a, pile_b, e, medi_b);
}

void	ft_if_pile_a(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_pile *tmp_a;
	t_pile *tmp_b;

	ft_mediane_a(pile_a, pile_b, e, medi_b);
	while ((ft_listlen(*pile_b) + e->pushed) < e->media_a - 1)
	{
		tmp_a = *pile_a;
		tmp_b = *pile_b;
		if (tmp_a->pos == e->min && e->rra <= 0 && e->pushed > 0)
			ft_ra_push(pile_a, e);
		else if (tmp_a->pos < e->media_a && tmp_a->pos > e->pushed)
			ft_pb(pile_a, pile_b);
		else
			ft_if_ra_push(pile_a, e);
	}
	if (e->rra > 0)
	{
		while (e->rra > 0)
		{
			ft_rotate_rev(pile_a);
			ft_printf("rra\n");
			e->rra--;
		}
	}
}
