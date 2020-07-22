/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:50:27 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 20:38:16 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_prec(char *str, int len, t_all *all)
{
	char	*str_new;
	char	*tmp;

	if (all->prec > len)
	{
		if (!(str_new = ft_strnew(all->prec - len)))
			return (NULL);
		str_new = ft_memset(str_new, '0', all->prec - len);
		if (!(tmp = ft_join_del(str_new, str, 1, 1)))
			return (NULL);
		return (tmp);
	}
	return (str);
}

int				ft_pointer(va_list args, t_all *all)
{
	uintmax_t	p;
	char		*str;
	int			len;

	p = (uintmax_t)va_arg(args, void *);
	if (all->f_prec && all->prec == 0 && p == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa_base(p, 16, all);
	len = ft_strlen(str);
	str = ft_prec(str, len, all);
	if (!str)
		return (-1);
	str = ft_join_del("0x", str, 0, 1);
	str = ft_str_flag_width(str, all);
	fd_putstr(str, all);
	free(str);
	return (0);
}
