/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:45:36 by mlink             #+#    #+#             */
/*   Updated: 2020/02/21 12:31:42 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_join_del(char const *s1, char const *s2, int a, int b)
{
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (!new)
		return (0);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	if (a == 1)
		free((void *)s1);
	if (b == 1)
		free((void *)s2);
	return (new);
}
