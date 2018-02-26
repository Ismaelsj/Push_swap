/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 09:58:10 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/19 17:16:33 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_get_tab(t_pile *pile_a)
{
	int		i;
	t_pile	*tmp;
	int		*str;

	tmp = pile_a;
	if (!(str = (int*)malloc(sizeof(int) * ft_listlen(pile_a))))
		return (0);
	i = ft_listlen(pile_a) - 1;
	while (tmp)
	{
		str[i] = tmp->nb;
		tmp = tmp->next;
		i--;
	}
	i = 0;
	ft_sort_tab(pile_a, str);
	return (str);
}

void	ft_position(t_pile **pile_a, int *tab)
{
	int		i;
	int		j;
	t_pile	*tmp1;

	i = 0;
	j = ft_listlen(*pile_a);
	while (i < j)
	{
		tmp1 = *pile_a;
		while (tab[i] != tmp1->nb)
			tmp1 = tmp1->next;
		tmp1->pos = i + 1;
		i++;
	}
	free(tab);
}

long	ft_get_e_max(t_pile *pile)
{
	t_pile	*tmp;
	long	i;

	tmp = pile;
	i = 0;
	while (tmp)
	{
		if (tmp->pos > i)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_get_mediane_b(t_media_b **lst, long nb)
{
	t_media_b *tmp;

	if (!(*lst))
	{
		if (!(tmp = (t_media_b*)malloc(sizeof(t_media_b))))
			return ;
		tmp->medi = nb;
		tmp->next = NULL;
		*lst = tmp;
	}
	else
	{
		if (!(tmp = (t_media_b*)malloc(sizeof(t_media_b))))
			return ;
		tmp->medi = nb;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	ft_del_maillon(t_media_b **lst)
{
	t_media_b *tmp;

	tmp = *lst;
	if (tmp->next)
	{
		*lst = tmp->next;
		free(tmp);
	}
	else
	{
		if (*lst)
			free(*lst);
		*lst = NULL;
	}
}
