/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:49:49 by mlink             #+#    #+#             */
/*   Updated: 2020/06/02 11:52:19 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wight_char(char c, t_all *all)
{
	char	*str;

	if (!(str = ft_strnew(all->width - 1)))
		return (-1);
	if (all->f_zero)
		str = ft_memset(str, '0', all->width - 1);
	else
		str = ft_memset(str, ' ', all->width - 1);
	if (all->f_minus)
	{
		write(all->fd, &c, 1);
		fd_putstr(str, all);
		all->count++;
	}
	else
	{
		fd_putstr(str, all);
		write(all->fd, &c, 1);
		all->count++;
	}
	free(str);
	return(0);
}

int			ft_char(va_list args, t_all *all, char c)
{
	if (c == 'c')
		c = (char)va_arg(args, int);
	else if (c == 'C')
		return(0);
	if (all->width > 0)
		ft_wight_char(c, all);
	else
	{
		write(all->fd, &c, 1);
		all->count++;
	}
	return(0);
}
