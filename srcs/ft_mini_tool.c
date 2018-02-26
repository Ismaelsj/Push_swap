/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:15:12 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/19 17:20:05 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_mini(t_pile **pile_a)
{
	ft_swap_top(pile_a);
	ft_printf("sa\n");
}

void	ft_rotate_rev_mini(t_pile **pile_a)
{
	ft_rotate_rev(pile_a);
	ft_printf("rra\n");
}

void	ft_swap_ra_mini(t_pile **pile_a)
{
	ft_rotate(pile_a);
	ft_printf("ra\n");
}
