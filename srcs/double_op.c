/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:51:55 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/16 10:56:14 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_pile **tmp_a, t_pile **tmp_b)
{
	ft_rotate(tmp_b);
	ft_rotate(tmp_a);
}

void	ft_rrotate_rev(t_pile **tmp_a, t_pile **tmp_b)
{
	ft_rotate_rev(tmp_b);
	ft_rotate_rev(tmp_a);
}

void	ft_sswap_top(t_pile **tmp_a, t_pile **tmp_b)
{
	ft_swap_top(tmp_b);
	ft_swap_top(tmp_a);
}
