/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_buox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:41:52 by mlink             #+#    #+#             */
/*   Updated: 2020/02/29 14:47:33 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_to_str(char *str, t_all *all, int base, uintmax_t x)
{
	char	*tmp;

	tmp = NULL;
	if (base == 8 && all->f_hash && x != 0)
		tmp = ft_join_del("0", str, 0, 1);
	else if (base == 16 && all->f_hash && x != 0 && !all->x)
		tmp = ft_join_del("0x", str, 0, 1);
	else if (base == 16 && all->f_hash && x != 0 && all->x)
		tmp = ft_join_del("0X", str, 0, 1);
	else if (all->f_hash && !all->f_prec && x != 0 && base != 16)
		tmp = ft_join_del("0", str, 0, 1);
	else
		return (str);
	return (tmp);
}

static char	*ft_prec(char *str, t_all *all, int base, uintmax_t x)
{
	char	*str_new;
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (base == 8 && all->f_hash && x != 0)
		len++;
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

static char	*ft_width_minus(char *str, char *str_new, t_all *all)
{
	char	*tmp;

	if (all->f_minus)
		tmp = ft_join_del(str, str_new, 1, 1);
	else
		tmp = ft_join_del(str_new, str, 1, 1);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*ft_width_flag(char *str, t_all *all, int base, uintmax_t x)
{
	int		len;
	char	*str_new;

	len = ft_strlen(str);
	if (all->f_hash && x != 0 && ((!all->f_prec && base != 16) || base == 8))
		len++;
	else if (base == 16 && all->f_hash && x != 0)
		len = len + 2;
	if (all->width > len)
	{
		if (!(str_new = ft_strnew(all->width - len)))
			return (NULL);
		if (all->f_zero && !all->f_prec)
			str_new = ft_memset(str_new, '0', all->width - len);
		else
			str_new = ft_memset(str_new, ' ', all->width - len);
		if (all->f_zero && !all->f_prec)
			str_new = ft_add_to_str(str_new, all, base, x);
		else
			str = ft_add_to_str(str, all, base, x);
		return (str = ft_width_minus(str, str_new, all));
	}
	str = ft_add_to_str(str, all, base, x);
	return (str);
}

int			ft_type_buox(va_list args, t_all *all, char c)
{
	uintmax_t	x;
	char		*str;
	int			base;

	base = ft_base(c, all);
	str = ft_cheng_mod_buox(args, all, base, &x);
	if (!str)
		return (0);
	if (!(str = ft_prec(str, all, base, x)))
		return (-1);
	if (all->f_minus)
		all->f_zero = 0;
	if (!(str = ft_width_flag(str, all, base, x)))
		return (-1);
	fd_putstr(str, all);
	free(str);
	return (0);
}
