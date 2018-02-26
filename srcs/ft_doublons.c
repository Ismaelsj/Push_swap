/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:15:21 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/18 18:15:26 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_doublons(t_pile **pile_a)
{
	t_pile *tmp1;
	t_pile *tmp2;

	tmp1 = *pile_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->nb == tmp1->nb)
			{
				ft_set_error();
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}
