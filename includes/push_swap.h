/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 14:28:39 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/27 09:16:08 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/includes/libft.h"
# include "../Libft/includes/ft_printf.h"
# include "../Libft/includes/get_next_line.h"

typedef struct		s_pile
{
	long			nb;
	long			pos;
	struct s_pile	*next;
}					t_pile;
typedef struct		s_medi
{
	long			medi;
	struct s_medi	*next;
}					t_media_b;
typedef struct		s_info
{
	long			max;
	long			min;
	long			media_a;
	long			media_b;
	long			pushed;
	long			rra;
}					t_media;
void				ft_swap_mini(t_pile **pile_a);
void				ft_rotate_rev_mini(t_pile **pile_a);
void				ft_swap_ra_mini(t_pile **pile_a);
void				ft_if_b(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_if_a(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
int					ft_doublons(t_pile **pile_a);
t_pile				*ft_newpile(long nb);
int					ft_del_list(t_pile *pile_a, t_pile *pile_b, t_media *e);
void				ft_sort_tab(t_pile *pile_a, int *str);
void				ft_mini_sort5(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_mini_sort3(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_quicksort(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_if_pile_b(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_if_pile_a(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_mediane_a(t_pile **pile_a, t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_mediane_b(t_pile **pile_b, t_media *e,
		t_media_b **medi_b);
void				ft_ra(t_pile **pile_a);
void				ft_rb(t_pile **pile_b);
void				ft_rrb(t_pile **pile_b);
void				ft_pb(t_pile **pile_a, t_pile **pile_b);
void				ft_pa(t_pile **pile_b, t_pile **pile_a);
void				ft_rrb_pa(t_pile **pile_b, t_pile **pile_a);
void				ft_sb_pa(t_pile **pile_b, t_pile **pile_a);
void				ft_ra_push(t_pile **pile_a, t_media *e);
void				ft_if_ra_push(t_pile **pile_a, t_media *e);
void				ft_sa_push(t_pile **pile_a, t_media *e);
void				ft_del_maillon(t_media_b **lst);
void				ft_get_mediane_b(t_media_b **lst, long nb);
long				ft_last_list(t_pile *pile_a);
void				ft_selection_sort(t_pile **pile_a, t_pile **pile_b);
long				ft_get_e_max(t_pile *pile);
int					ft_is_sort(t_pile **pile_a, t_pile **pile_b);
int					ft_set_error(void);
int					ft_listlen(t_pile *pile_a);
int					*ft_get_tab(t_pile *pile_a);
void				ft_position(t_pile **pile_a, int *tab);
void				ft_write(t_pile *pile_a, t_pile *pile_b);
int					ft_error(char **entier);
long				ft_atol(const char *str);
void				ft_swap_top(t_pile **list);
void				ft_sswap_top(t_pile **tmp_a, t_pile **tmp_b);
void				ft_push_top(t_pile **list_a, t_pile **list_b);
void				ft_rotate(t_pile **list);
void				ft_rrotate(t_pile **tmp_a, t_pile **tmp_b);
void				ft_rotate_rev(t_pile **list);
void				ft_rrotate_rev(t_pile **tmp_a, t_pile **tmp_b);
int					ft_put_in(char *entier, t_pile **begin_list, int j);
int					ft_get_list(char **entier, int argc, t_pile **begin_list);
#endif
