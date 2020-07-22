/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheng_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:16:52 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 22:18:12 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cheng_mod(va_list args, t_all *all, intmax_t *x)
{
	if (all->mod_z)
		*x = (size_t)va_arg(args, intmax_t);
	else if (all->mod_j)
		*x = va_arg(args, intmax_t);
	else if (all->mod_h)
		*x = (short int)va_arg(args, intmax_t);
	else if (all->mod_hh)
		*x = (char)va_arg(args, intmax_t);
	else if (all->mod_l)
		*x = (long int)va_arg(args, intmax_t);
	else if (all->mod_ll)
		*x = (long long int)va_arg(args, intmax_t);
	else
		*x = (int)va_arg(args, intmax_t);
}

char	*ft_cheng_mod_buox(va_list args, t_all *all,
										int base, uintmax_t *x)
{
	char	*str;

	if (all->mod_z)
		*x = (size_t)va_arg(args, uintmax_t);
	else if (all->mod_j)
		*x = va_arg(args, uintmax_t);
	else if (all->mod_h)
		*x = (unsigned short int)va_arg(args, uintmax_t);
	else if (all->mod_hh)
		*x = (unsigned char)va_arg(args, uintmax_t);
	else if (all->mod_l)
		*x = (unsigned long)va_arg(args, uintmax_t);
	else if (all->mod_ll)
		*x = (unsigned long long)va_arg(args, uintmax_t);
	else
		*x = (unsigned int)va_arg(args, uintmax_t);
	if (*x == 0 && all->f_prec && all->prec == 0 && base != 8)
		str = ft_strnew(1);
	else if (!all->f_hash && *x == 0 && all->f_prec && all->prec == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa_base(*x, base, all);
	if (!str)
		return (NULL);
	return (str);
}
