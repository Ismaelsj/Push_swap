/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:37:55 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/17 16:52:24 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_newpile(long nb)
{
	t_pile		*list;
	static int	j;

	if (!(list = (t_pile*)malloc(sizeof(t_pile))))
	{
		ft_set_error();
		return (NULL);
	}
	j++;
	list->nb = nb;
	list->pos = j;
	list->next = NULL;
	return (list);
}
