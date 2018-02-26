/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:18:57 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/27 09:15:33 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_del_list(t_pile *pile_a, t_pile *pile_b, t_media *e)
{
	t_pile *tmp1;
	t_pile *tmp2;

	tmp2 = pile_a;
	if (e)
		free(e);
	while (tmp2)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		free(tmp1);
	}
	tmp2 = pile_b;
	while (tmp2)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		free(tmp1);
	}
	return (0);
}
