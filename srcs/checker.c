/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 09:58:10 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/25 18:29:34 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static int		ft_commandes(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
			|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
			|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
			|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
			|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
			|| ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "") == 0)
		return (1);
	else
		return (0);
}

static void		operat(t_pile **tmp_a, t_pile **tmp_b, char *buff)
{
	if (ft_strcmp(buff, "sa") == 0)
		ft_swap_top(tmp_a);
	else if (ft_strcmp(buff, "sb") == 0)
		ft_swap_top(tmp_b);
	else if (ft_strcmp(buff, "ss") == 0)
		ft_sswap_top(tmp_a, tmp_b);
	else if (ft_strcmp(buff, "pa") == 0)
		ft_push_top(tmp_b, tmp_a);
	else if (ft_strcmp(buff, "pb") == 0)
		ft_push_top(tmp_a, tmp_b);
	else if (ft_strcmp(buff, "ra") == 0)
		ft_rotate(tmp_a);
	else if (ft_strcmp(buff, "rb") == 0)
		ft_rotate(tmp_b);
	else if (ft_strcmp(buff, "rr") == 0)
		ft_rrotate(tmp_a, tmp_b);
	else if (ft_strcmp(buff, "rrb") == 0)
		ft_rotate_rev(tmp_b);
	else if (ft_strcmp(buff, "rra") == 0)
		ft_rotate_rev(tmp_a);
	else if (ft_strcmp(buff, "rrr") == 0)
		ft_rrotate_rev(tmp_a, tmp_b);
}

static void		checker(t_pile **pile_a, t_pile **pile_b)
{
	char	*buff;
	char	*str;
	int		i;

	buff = NULL;
	while (get_next_line(0, &buff) == 1)
	{
		i = 0;
		while (buff[i] && ft_isalpha(buff[i]) == 0 && buff[i] != 32)
			i++;
		str = ft_strdup(buff + i);
		free(buff);
		buff = NULL;
		if (ft_commandes(str) == 1)
			operat(pile_a, pile_b, str);
		else
		{
			free(str);
			ft_set_error();
		}
		free(str);
	}
}

int				main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_media	*e;

	e = NULL;
	if (ac < 2)
		return (0);
	ft_error(av);
	if (!(ft_get_list(av, ac, &pile_a)))
		return (ft_set_error());
	if (!(pile_a))
		return (0);
	if (ft_doublons(&pile_a) == 0)
		return (ft_set_error());
	ft_position(&pile_a, ft_get_tab(pile_a));
	checker(&pile_a, &pile_b);
	if (ft_is_sort(&pile_a, &pile_b) == 1)
		ft_printf("%sOK%s\n", GREEN, RESET);
	else
		ft_printf("%sKO%s\n", RED, RESET);
	ft_del_list(pile_a, pile_b, e);
	return (0);
}
