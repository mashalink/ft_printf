/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:45:36 by mlink             #+#    #+#             */
/*   Updated: 2020/02/21 12:33:06 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(const char c)
{
	if (ft_strchr("bdDioOuUxXfcCsSp%%", c) != 0)
		return (1);
	return (0);
}

int	ft_is_flag(const char c)
{
	if (ft_strchr("#0-+ ", c) != 0)
		return (1);
	return (0);
}

int	ft_is_width(const char c)
{
	if (ft_strchr("0123456789*", c) != 0)
		return (1);
	return (0);
}

int	ft_is_prec(const char c)
{
	if (ft_strchr(".0123456789*", c) != 0)
		return (1);
	return (0);
}

int	ft_is_mod(const char c)
{
	if (ft_strchr("hlLjz", c) != 0)
		return (1);
	return (0);
}
