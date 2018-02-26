/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:58:48 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/27 09:16:39 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_init(t_media *e, t_pile *pile_a)
{
	ft_doublons(&pile_a);
	e->media_a = 0;
	e->media_b = 0;
	e->pushed = 0;
	e->rra = 0;
	e->min = 1;
	e->max = ft_get_e_max(pile_a);
	ft_position(&pile_a, ft_get_tab(pile_a));
}

long			ft_last_list(t_pile *pile_a)
{
	t_pile *tmp;

	tmp = pile_a;
	if (!(pile_a))
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->pos);
}

void			ft_quicksort(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b)
{
	t_pile		*tmp_a;
	t_pile		*tmp_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (e->pushed == e->max || ft_is_sort(pile_a, pile_b) == 1)
		return ;
	else if (tmp_a->pos == e->min)
	{
		ft_ra_push(pile_a, e);
		ft_quicksort(pile_a, pile_b, e, medi_b);
		return ;
	}
	else if (tmp_a->next->pos == e->min)
	{
		ft_sa_push(pile_a, e);
		ft_quicksort(pile_a, pile_b, e, medi_b);
		return ;
	}
	else if (tmp_b)
		ft_if_pile_b(pile_a, pile_b, e, medi_b);
	if (tmp_a)
		ft_if_pile_a(pile_a, pile_b, e, medi_b);
	ft_quicksort(pile_a, pile_b, e, medi_b);
	return ;
}

int				main(int ac, char **av)
{
	t_media		*e;
	t_pile		*pile_a;
	t_pile		*pile_b;
	t_media_b	*medi_b;

	ft_error(av);
	if (!(e = (t_media*)malloc(sizeof(t_media))))
		return (0);
	if (ac < 2)
		return (0);
	if (!(ft_get_list(av, ac, &pile_a)))
		return (ft_set_error());
	ft_init(e, pile_a);
	if (ft_is_sort(&pile_a, &pile_b) == 1)
		return (ft_del_list(pile_a, pile_b, e));
	if (e->max < 4)
		ft_mini_sort3(&pile_a, &pile_b, e, &medi_b);
	else if (e->max < 6)
		ft_mini_sort5(&pile_a, &pile_b, e, &medi_b);
	else
		ft_quicksort(&pile_a, &pile_b, e, &medi_b);
	ft_del_list(pile_a, pile_b, e);
	free(medi_b);
	return (0);
}
