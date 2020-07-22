/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:11:29 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 19:12:53 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_round_x(long double x, t_all *all)
{
	double	round;
	int		i;

	if (x < 0)
	{
		all->neg = 1;
		x *= -1;
	}
	round = 0.5;
	i = all->prec;
	while (i-- > 0)
		round /= 10;
	x = x + round;
	return (x);
}

static char			*ft_after_dot_num(long double x, t_all *all)
{
	int		i;
	char	*str;
	char	*str_plus;
	int		x_sav;

	i = all->prec;
	str = ft_strnew(0);
	str_plus = ft_strnew(1);
	while (i-- > 0)
	{
		x *= 10;
		x_sav = (int)x;
		str_plus[0] = (x_sav % 10) + '0';
		str = ft_join_del(str, str_plus, 1, 0);
		x = x - (intmax_t)x;
	}
	free(str_plus);
	return (str);
}

static char			*ft_prec(long double x, t_all *all)
{
	char	*str;
	char	*str2;
	char	*tmp;

	x = ft_round_x(x, all);
	if (!(str = ft_itoa_base((intmax_t)x, 10, all)))
		return (NULL);
	if (!all->prec && !all->f_hash)
		return (str);
	str2 = ft_join_del(str, ".", 1, 0);
	if (!(str = ft_after_dot_num((x - (intmax_t)x), all)))
		return (NULL);
	if (!(tmp = ft_join_del(str2, str, 1, 1)))
		return (NULL);
	return (tmp);
}

int					ft_double(va_list args, t_all *all)
{
	long double	x;
	char		*str;
	int			len;

	if (all->mod_big_l)
		x = (long double)va_arg(args, long double);
	else
		x = (long double)va_arg(args, double);
	if (!all->f_prec && all->prec == 0)
		all->prec = 6;
	if (!(str = ft_prec(x, all)))
		return (-1);
	len = ft_strlen(str);
	if (len > all->width)
		if (!(str = ft_join_f(str, all)))
			return (-1);
	if (!(str = ft_str_flag_width(str, all)))
		return (-1);
	if (all->neg)
		str = ft_join_del("-", str, 0, 1);
	fd_putstr(str, all);
	free(str);
	return (0);
}
