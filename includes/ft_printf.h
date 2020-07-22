/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:07:10 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 19:46:14 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*
**	<W> - White color
**	<D> - Black color
**	<R> - Red color
**	<G> - Green color
**	<Y> - Yellow color
**	<B> - Blue color
**	<M> - Magenta color
**	<C> - Cyan color
**	<0> - Off
**	--background color--
**	<w> - white
**	<d> - black
**	<r> - red
**	<g> - green
**	<y> - yellow
**	<b> - blue
**	<m> - magenta
**	<c> - cyan
**	<o> - Default
**	--class formatting--
**	<1> - Bold
**	<2> - Italic
**	<3> - Underlined
**	<4> - Blink
**  <5> - Reverse
**	<6> - Hidden
**	<7> - Dim
*/

typedef struct	s_all
{
	int			mod_l;
	int			mod_ll;
	int			mod_h;
	int			mod_hh;
	int			mod_j;
	int			mod_z;
	int			mod_big_l;
	int			prec;
	int			f_prec;
	int			width;
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_hash;
	int			f_zero;
	int			count;
	int			save_count;
	int			fd;
	int			neg;
	int			x;
	char		buffer[1024];
}				t_all;

int				ft_printf(const char *form, ...);
int				fd_printf(int fd, const char *form, ...);

int				ft_save(const char *form, size_t i, t_all *all, va_list args);

int				ft_is_mod(const char c);
int				ft_is_prec(const char c);
int				ft_is_width(const char c);
int				ft_is_flag(const char c);
int				ft_is_type(const char c);

int				ft_set_print(const char *form, size_t i, t_all *all);
int				ft_char(va_list args, t_all *all, char c);
int				ft_str(va_list args, t_all *all);
int				ft_pointer(va_list args, t_all *all);
int				ft_type_buox(va_list args, t_all *all, char c);
int				ft_double(va_list args, t_all *all);
int				ft_set_print(const char *form, size_t i, t_all *all);

int				ft_int(va_list args, t_all *all);
char			*ft_str_flag_width(char *str, t_all *all);

int				ft_base(char c, t_all *all);
char			*ft_join_f(char *str, t_all *all);
void			fd_putstr(const char *s, t_all *all);
char			*ft_itoa_base(uintmax_t x, int base, t_all *all);

void			ft_cheng_mod(va_list args, t_all *all, intmax_t *x);
char			*ft_cheng_mod_buox(va_list args, t_all *all,
											int base, uintmax_t *x);

void			print_buffer(t_all *all);

#endif
