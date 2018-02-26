/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:13:43 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/17 13:16:24 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_pile **pile_b)
{
	ft_rotate(pile_b);
	ft_printf("rb\n");
}

void	ft_pa(t_pile **pile_b, t_pile **pile_a)
{
	ft_push_top(pile_b, pile_a);
	ft_printf("pa\n");
}

void	ft_rrb_pa(t_pile **pile_b, t_pile **pile_a)
{
	ft_rotate_rev(pile_b);
	ft_printf("rrb\n");
	ft_push_top(pile_b, pile_a);
	ft_printf("pa\n");
}

void	ft_sb_pa(t_pile **pile_b, t_pile **pile_a)
{
	ft_swap_top(pile_b);
	ft_printf("sb\n");
	ft_push_top(pile_b, pile_a);
	ft_printf("pa\n");
}

void	ft_rrb(t_pile **pile_b)
{
	ft_rotate_rev(pile_b);
	ft_printf("rrb\n");
}
