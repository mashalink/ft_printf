/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:34:40 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 22:19:20 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_zero_minus(char *str1, char *str2, t_all *all, int len)
{
	char	*str_new;

	if (all->f_zero)
	{
		str2 = ft_memset(str2, '0', len);
		if (!(str_new = ft_join_f(str2, all)))
			return (NULL);
	}
	else
	{
		str_new = ft_memset(str2, ' ', len);
		if (!(str1 = ft_join_f(str1, all)))
			return (NULL);
	}
	if (all->f_minus)
		str_new = ft_join_del(str1, str_new, 1, 1);
	else
		str_new = ft_join_del(str_new, str1, 1, 1);
	if (!str_new)
		return (NULL);
	return (str_new);
}

static char	*ft_str_prec(char *str, t_all *all)
{
	char	*str_new;
	int		len;

	len = ft_strlen(str);
	if (all->prec > len)
	{
		if (!(str_new = ft_strnew(all->prec - len)))
			return (NULL);
		str_new = ft_memset(str_new, '0', all->prec - len);
		if (!(str_new = ft_join_del(str_new, str, 1, 1)))
			return (NULL);
		if (all->f_zero == 1)
			all->f_zero = 0;
		len = ft_strlen(str_new);
		if (len > all->width)
		{
			if (!(str_new = ft_join_f(str_new, all)))
				return (NULL);
		}
		return (str_new);
	}
	return (str);
}

char		*ft_str_flag_width(char *str, t_all *all)
{
	int		len;
	char	*str_new;
	char	*tmp;

	len = ft_strlen(str);
	if (all->width > len)
	{
		if (all->neg || all->f_plus || all->f_space)
		{
			if (!(str_new = ft_strnew(all->width - len - 1)))
				return (NULL);
			tmp = ft_zero_minus(str, str_new, all, all->width - len - 1);
		}
		else
		{
			if (!(str_new = ft_strnew(all->width - len)))
				return (NULL);
			tmp = ft_zero_minus(str, str_new, all, all->width - len);
		}
		return (tmp);
	}
	str = ft_join_f(str, all);
	return (str);
}

static char	*ft_next_step(intmax_t x, t_all *all)
{
	char	*str;

	if (x == 0 && all->f_prec && all->prec == 0)
		str = ft_strnew(0);
	else
	{
		if (x < 0)
			all->neg = 1;
		if (x + 1 == -9223372036854775807)
			str = ft_strdup("9223372036854775808");
		else
		{
			if (x < 0)
				x *= -1;
			str = ft_itoa_base(x, 10, all);
		}
	}
	if (!str)
		return (0);
	return (str);
}

int			ft_int(va_list args, t_all *all)
{
	intmax_t	x;
	char		*str;

	ft_cheng_mod(args, all, &x);
	str = ft_next_step(x, all);
	if (!(str = ft_str_prec(str, all)))
		return (0);
	if (all->f_prec)
		all->f_zero = 0;
	if (!(str = ft_str_flag_width(str, all)))
		return (0);
	if (all->neg)
		str = ft_join_del("-", str, 0, 1);
	fd_putstr(str, all);
	free(str);
	return (0);
}
