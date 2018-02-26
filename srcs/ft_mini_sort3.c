/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:07 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/19 17:15:17 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_op_a(t_pile **pile_a, t_pile **pile_b, t_media *e)
{
	t_pile *tmp_a;

	tmp_a = *pile_a;
	if (tmp_a->pos <= (e->min + 1))
		ft_pb(pile_a, pile_b);
	else
		ft_ra(pile_a);
}

static void		ft_op_b(t_pile **pile_a, t_pile **pile_b)
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

static void		ft_mini(t_pile **p_a, t_pile **p_b, t_media *e)
{
	t_pile *tmp;

	tmp = *p_a;
	if (ft_is_sort(p_a, p_b) == 1)
		return ;
	else if (ft_last_list(*p_a) > tmp->pos && tmp->next->pos == e->min)
		ft_swap_mini(p_a);
	else if (tmp->pos > tmp->next->pos && tmp->next->pos > ft_last_list(*p_a))
	{
		ft_swap_mini(p_a);
		ft_rotate_rev_mini(p_a);
	}
	else if (tmp->pos == ft_get_e_max(*p_a) && tmp->next->pos == e->min)
		ft_swap_ra_mini(p_a);
	else if (tmp->pos == e->min && tmp->next->pos == ft_get_e_max(*p_a))
	{
		ft_rotate_rev_mini(p_a);
		ft_swap_mini(p_a);
	}
	else
	{
		ft_swap_ra_mini(p_a);
		ft_swap_ra_mini(p_a);
	}
}

void			ft_mini_sort3(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_pile *tmp_a;
	t_pile *tmp_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (!(*pile_b) && ft_is_sort(pile_a, pile_b) == 1)
		return ;
	if (ft_listlen(*pile_a) < 4)
		ft_mini(pile_a, pile_b, e);
	else if (!(*pile_b))
	{
		while (ft_listlen(*pile_a) > e->max - 1)
			ft_op_a(pile_a, pile_b, e);
		ft_mini_sort3(pile_a, pile_b, e, medi_b);
		return ;
	}
	while (*pile_b)
		ft_op_b(pile_a, pile_b);
	ft_mini_sort3(pile_a, pile_b, e, medi_b);
	return ;
}
