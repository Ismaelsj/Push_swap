/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:04:19 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/17 11:22:41 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pile **pile_a)
{
	ft_rotate(pile_a);
	ft_printf("ra\n");
}

void	ft_pb(t_pile **pile_a, t_pile **pile_b)
{
	ft_push_top(pile_a, pile_b);
	ft_printf("pb\n");
}

void	ft_ra_push(t_pile **pile_a, t_media *e)
{
	ft_rotate(pile_a);
	ft_printf("ra\n");
	e->min++;
	e->pushed++;
}

void	ft_sa_push(t_pile **pile_a, t_media *e)
{
	ft_swap_top(pile_a);
	ft_printf("sa\n");
	ft_rotate(pile_a);
	ft_printf("ra\n");
	e->min++;
	e->pushed++;
}

void	ft_if_ra_push(t_pile **pile_a, t_media *e)
{
	ft_rotate(pile_a);
	ft_printf("ra\n");
	if (e->pushed > 0)
		e->rra++;
}
