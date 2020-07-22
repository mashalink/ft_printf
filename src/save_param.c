/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:41:56 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 22:16:11 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_save_flag(const char *form, size_t i, t_all *all)
{
	if (form[i] == '-')
		all->f_minus = 1;
	if (form[i] == '+')
		all->f_plus = 1;
	if (form[i] == ' ')
		all->f_space = 1;
	if (all->f_space == 1 && all->f_plus == 1)
		all->f_space = 0;
	if (form[i] == '#')
		all->f_hash = 1;
	if (form[i] == '0')
		all->f_zero = 1;
	if (all->f_minus)
		all->f_zero = 0;
}

static void	ft_save_mod(const char *form, size_t i, t_all *all)
{
	size_t j;
	size_t k;

	k = i - 1;
	j = i + 1;
	if (form[k] != 'l' && form[i] == 'l' && form[j] != 'l')
		all->mod_l = 1;
	if (form[i] == 'l' && form[j] == 'l')
		all->mod_ll = 1;
	if (form[k] != 'h' && form[i] == 'h' && form[j] != 'h')
		all->mod_h = 1;
	if (form[i] == 'h' && form[j] == 'h')
		all->mod_hh = 1;
	if (form[i] == 'j')
		all->mod_j = 1;
	if (form[i] == 'z')
		all->mod_z = 1;
	if (form[i] == 'L')
		all->mod_big_l = 1;
}

static int	ft_save_width(const char *form, size_t i,
							t_all *all, va_list args)
{
	all->width = 0;
	if (form[i] == '*')
	{
		all->width = va_arg(args, int);
		if (all->width < 0)
		{
			all->f_zero = 0;
			all->width *= -1;
			all->f_minus = 1;
		}
	}
	else if ('0' <= form[i] && form[i] <= '9')
	{
		while ('0' <= form[i] && form[i] <= '9')
			all->width = all->width * 10 + form[i++] - '0';
		i--;
	}
	return (i);
}

static int	ft_save_prec(const char *form, size_t i, t_all *all, va_list args)
{
	int j;

	j = i + 1;
	if (form[j] == '*' || ('0' <= form[j] && form[j] <= '9'))
		i++;
	all->prec = 0;
	all->f_prec = 1;
	if (form[i] == '*')
	{
		all->prec = va_arg(args, int);
		if (all->prec < 0)
		{
			all->f_prec = 0;
			all->prec = 0;
		}
	}
	else if ('0' <= form[i] && form[i] <= '9')
	{
		while ('0' <= form[i] && form[i] <= '9')
			all->prec = all->prec * 10 + form[i++] - '0';
		i--;
	}
	return (i);
}

int			ft_save(const char *form, size_t i, t_all *all, va_list args)
{
	while (ft_is_flag(form[i]) || ft_is_mod(form[i]) ||
			ft_is_prec(form[i]) || ft_is_width(form[i]))
	{
		if (ft_is_flag(form[i]))
			ft_save_flag(form, i, all);
		else if (ft_is_width(form[i]))
			i = ft_save_width(form, i, all, args);
		else if (form[i] == '.')
			i = ft_save_prec(form, i, all, args);
		else if (ft_is_mod(form[i]))
			ft_save_mod(form, i, all);
		i++;
	}
	return (i);
}
