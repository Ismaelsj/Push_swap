/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:25:53 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/26 09:30:25 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_top(t_pile **list)
{
	t_pile	*tmp1;
	t_pile	*tmp2;
	long	i;

	if (*list == NULL)
		return ;
	tmp2 = *list;
	tmp1 = *list;
	tmp2 = tmp2->next;
	i = tmp1->nb;
	tmp1->nb = tmp2->nb;
	tmp2->nb = i;
	i = tmp1->pos;
	tmp1->pos = tmp2->pos;
	tmp2->pos = i;
}

void	ft_push_top(t_pile **list_a, t_pile **list_b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int		i;

	i = 0;
	if (*list_a == NULL)
		return ;
	tmp_a = *list_a;
	tmp_b = *list_b;
	*list_a = tmp_a->next;
	tmp_a->next = *list_b;
	*list_b = tmp_a;
}

void	ft_rotate(t_pile **list)
{
	t_pile *tmp1;
	t_pile *tmp2;
	t_pile *tmp3;

	if (*list == NULL || ft_listlen(*list) == 1)
		return ;
	tmp1 = *list;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp3 = *list;
	tmp2 = *list;
	tmp2 = tmp2->next;
	tmp1->next = tmp3;
	tmp3->next = NULL;
	*list = tmp2;
}

void	ft_rotate_rev(t_pile **list)
{
	t_pile *tmp1;
	t_pile *tmp2;
	t_pile *tmp3;

	if (*list == NULL || ft_listlen(*list) == 1)
		return ;
	tmp1 = *list;
	tmp2 = *list;
	tmp3 = *list;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp3;
	tmp2->next = NULL;
	*list = tmp1;
}
