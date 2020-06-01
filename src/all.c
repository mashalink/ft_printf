/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:08:52 by mlink             #+#    #+#             */
/*   Updated: 2020/03/02 17:06:49 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_base(char c, t_all *all)
{
	int base;

	base = 10;
	if (c == 'b')
		base = 2;
	else if (c == 'o' || c == 'O')
	{
		base = 8;
		if (c == 'O')
			all->mod_l = 1;
	}
	else if (c == 'U')
		all->mod_l = 1;
	else if (c == 'x' || c == 'X')
	{
		base = 16;
		all->x = c == 'X' ? 1 : 0;
	}
	return (base);
}

char		*ft_join_f(char *str, t_all *all)
{
	char	*str_new;

	if (all->neg || all->f_plus || all->f_space)
	{
		if (all->neg)
			str_new = ft_join_del("-", str, 0, 1);
		else if (all->f_plus)
		{
			str_new = ft_join_del("+", str, 0, 1);
		}
		else
			str_new = ft_join_del(" ", str, 0, 1);
		if (!str_new)
			return (NULL);
		all->neg = 0;
		all->f_plus = 0;
		all->f_space = 0;
		return (str_new);
	}
	return (str);
}

void		fd_putstr(const char *s, t_all *all)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i])
		{
			write(all->fd, &s[i++], 1);
			all->count++;
		}
}

static char	*ft_clean_str(int len, uintmax_t x)
{
	char	*str;

	if (x == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '0';
		return (str);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	return (str);
}

char		*ft_itoa_base(uintmax_t x, int base, t_all *all)
{
	char		*str;
	char		*base_s;
	uintmax_t	nbr;
	int			len;

	len = 0;
	nbr = x;
	base_s = "0123456789abcdef";
	if (all->x == 1)
		base_s = "0123456789ABCDEF";
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	str = ft_clean_str(len, x);
	while (x > 0)
	{
		str[--len] = base_s[x % base];
		x /= base;
	}
	return (str);
}
