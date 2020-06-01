/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:48:40 by mlink             #+#    #+#             */
/*   Updated: 2020/03/03 15:51:53 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_s(char *str, t_all *all, int len)
{
	char	*str_new;
	char	*tmp;

	if (all->width > len)
	{
		if (!(str_new = ft_strnew(all->width - len)))
			return (NULL);
		if (all->f_zero)
			str_new = ft_memset(str_new, '0', all->width - len);
		else
			str_new = ft_memset(str_new, ' ', all->width - len);
		if (all->f_minus)
			tmp = ft_join_del(str, str_new, 1, 1);
		else
			tmp = ft_join_del(str_new, str, 1, 1);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	return (str);
}

static char	*ft_prec_s(char *str, t_all *all, int len)
{
	char	*new;

	if (all->f_prec && all->prec < len)
	{
		if (!(new = ft_strnew(all->prec)))
			return (NULL);
		new = ft_strncpy(new, str, all->prec);
		free(str);
		return (new);
	}
	return (str);
}

int			ft_str(va_list args, t_all *all)
{
	char	*str;
	int		len;

	str = va_arg(args, char*);
	if (!str)
		str = "(null)";
	str = ft_strdup(str);
	len = ft_strlen(str);
	if (!(str = ft_prec_s(str, all, len)))
		return (0);
	len = ft_strlen(str);
	if (!(str = ft_width_s(str, all, len)))
		return (0);
	fd_putstr(str, all);
	free(str);
	return (0);
}
