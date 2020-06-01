/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:11:14 by mlink             #+#    #+#             */
/*   Updated: 2020/02/29 14:59:37 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_clean(t_all *all)
{
	all->mod_l = 0;
	all->mod_ll = 0;
	all->mod_h = 0;
	all->mod_hh = 0;
	all->mod_j = 0;
	all->mod_z = 0;
	all->mod_big_l = 0;
	all->prec = 0;
	all->f_prec = 0;
	all->width = 0;
	all->f_minus = 0;
	all->f_plus = 0;
	all->f_space = 0;
	all->f_hash = 0;
	all->f_zero = 0;
	all->fd = 0;
	all->neg = 0;
	all->x = 0;
}

static int	print_args(va_list args, t_all *all, char c)
{
	if (c == 'd' || c == 'i')
		ft_int(args, all);
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X'
	|| c == 'b' || c == 'u' || c == 'U')
		ft_type_buox(args, all, c);
	else if (c == 's')
		ft_str(args, all);
	else if (c == 'p')
		ft_pointer(args, all);
	else if (c == 'f' || c == 'F')
		ft_double(args, all);
	else
		ft_char(args, all, c);
	return (0);
}

static int	ft_first(const char *form, va_list args, int fd)
{
	size_t	i;
	t_all	all;

	i = 0;
	all.count = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			ft_clean(&all);
			all.fd = fd;
			i = ft_save(form, i, &all, args);
			if (i >= ft_strlen(form))
				break ;
			print_args(args, &all, form[i++]);
		}
		if (form[i] == '{')
			i = ft_set_print(form, i, &all);
		while (form[i] && form[i] != '%')
		{
			write(fd, &form[i++], 1);
			all.count++;
		}
	}
	return (all.count);
}

int			ft_printf(const char *form, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, form);
	count = ft_first(form, args, 1);
	va_end(args);
	return (count);
}

int			fd_printf(int fd, const char *form, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, form);
	count = ft_first(form, args, fd);
	va_end(args);
	return (count);
}
