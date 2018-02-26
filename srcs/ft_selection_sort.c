/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:10:03 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/22 15:33:54 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_next(t_pile **pile_b, long x)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = *pile_b;
	while (tmp && tmp->pos != x)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void		ft_selection_sort(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp_b;
	int		i;

	tmp_b = *pile_b;
	i = ft_get_e_max(*pile_b);
	while (*pile_b)
	{
		i = ft_get_e_max(*pile_b);
		tmp_b = *pile_b;
		if (tmp_b->pos == i)
			ft_pa(pile_b, pile_a);
		else if (ft_last_list(*pile_b) == i || ft_last_list(*pile_b) == i - 1)
			ft_rrb_pa(pile_b, pile_a);
		else if (tmp_b->next && tmp_b->next->pos == i)
			ft_sb_pa(pile_b, pile_a);
		else if (ft_next(pile_b, i) > (ft_listlen(*pile_b) / 2))
			ft_rrb(pile_b);
		else if (ft_next(pile_b, i) <= (ft_listlen(*pile_b) / 2))
			ft_rb(pile_b);
	}
}
