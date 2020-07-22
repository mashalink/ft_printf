/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:54:23 by mlink             #+#    #+#             */
/*   Updated: 2020/07/21 16:46:45 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_print(const char c)
{
	if (ft_strchr("WDRGYBMC0wdrgybmco1234567", c) != 0)
		return (1);
	return (0);
}

static void	ft_color(char c, t_all *all)
{
	if (c == 'W')
		fd_putstr("\x1b[37m", all);
	else if (c == 'D')
		fd_putstr("\x1b[30m", all);
	else if (c == 'R')
		fd_putstr("\x1b[31m", all);
	else if (c == 'G')
		fd_putstr("\x1b[32m", all);
	else if (c == 'Y')
		fd_putstr("\x1b[33m", all);
	else if (c == 'B')
		fd_putstr("\x1b[34m", all);
	else if (c == 'M')
		fd_putstr("\x1b[35m", all);
	else if (c == 'C')
		fd_putstr("\x1b[36m", all);
	else if (c == '0')
		fd_putstr("\x1b[0m", all);
}

static void	ft_back_color(char c, t_all *all)
{
	if (c == 'w')
		fd_putstr("\x1b[47m", all);
	else if (c == 'd')
		fd_putstr("\x1b[40m", all);
	else if (c == 'r')
		fd_putstr("\x1b[41m", all);
	else if (c == 'g')
		fd_putstr("\x1b[42m", all);
	else if (c == 'y')
		fd_putstr("\x1b[43m", all);
	else if (c == 'b')
		fd_putstr("\x1b[44m", all);
	else if (c == 'm')
		fd_putstr("\x1b[45m", all);
	else if (c == 'c')
		fd_putstr("\x1b[46m", all);
	else if (c == 'o')
		fd_putstr("\x1b[27m", all);
}

static void	ft_formtting(char c, t_all *all)
{
	if (c == '1')
		fd_putstr("\x1b[1m", all);
	else if (c == '2')
		fd_putstr("\x1b[3m", all);
	else if (c == '3')
		fd_putstr("\x1b[4m", all);
	else if (c == '4')
		fd_putstr("\x1b[5m", all);
	else if (c == '5')
		fd_putstr("\x1b[7m", all);
	else if (c == '6')
		fd_putstr("\x1b[8m", all);
	else if (c == '7')
		fd_putstr("\x1b[2m", all);
}

int			ft_set_print(const char *form, size_t i, t_all *all)
{
	size_t	k;
	size_t	j;

	i++;
	k = i + 1;
	j = i + 2;
	while (form[i] == '{' && ft_is_print(form[k]) && form[j] == '}')
	{
		i += 3;
		ft_color(form[k], all);
		ft_back_color(form[k], all);
		ft_formtting(form[k], all);
		k = i + 1;
		j = i + 2;
	}
	return (i);
}
