/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:42:55 by mlink             #+#    #+#             */
/*   Updated: 2020/07/22 19:46:37 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buffer(t_all *all)
{
	all->buffer[all->count] = '\0';
	write(all->fd, &all->buffer, all->count);
	all->save_count += all->count;
	all->count = 0;
}
