/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:11:14 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 21:00:19 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_all	*ft_clean(t_all *all)
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
	return (all);
}

static int		print_args(va_list args, t_all *all, char c, int i)
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
	return (++i);
}

static int		ft_first(const char *form, va_list args, int fd, t_all *all)
{
	size_t	i;

	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			all = ft_clean(all);
			all->fd = fd;
			i = ft_set_print(form, i, all);
			i = ft_save(form, i, all, args);
			if (i >= ft_strlen(form))
				break ;
			i = print_args(args, all, form[i], i);
		}
		while (form[i] && form[i] != '%')
		{
			if (all->count < 1024)
				all->buffer[all->count++] = form[i++];
			else
				print_buffer(all);
		}
	}
	all->save_count = all->count;
	return (all->save_count);
}

int				ft_printf(const char *form, ...)
{
	va_list	args;
	int		count;
	t_all	*all;

	all = NULL;
	count = 0;
	if (!(all = (t_all *)ft_memalloc(sizeof(t_all))))
		exit(0);
	all->count = 0;
	all->save_count = 0;
	va_start(args, form);
	count = ft_first(form, args, 1, all);
	va_end(args);
	all->buffer[all->count] = '\0';
	write(1, all->buffer, all->count);
	free(all);
	return (count);
}

int				fd_printf(int fd, const char *form, ...)
{
	va_list	args;
	int		count;
	t_all	*all;

	all = NULL;
	count = 0;
	if (!(all = (t_all *)ft_memalloc(sizeof(t_all))))
		exit(0);
	all->count = 0;
	all->save_count = 0;
	va_start(args, form);
	count = ft_first(form, args, fd, all);
	va_end(args);
	all->buffer[all->count] = '\0';
	write(fd, all->buffer, all->count);
	free(all);
	return (count);
}
