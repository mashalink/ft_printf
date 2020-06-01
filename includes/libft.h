/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:17:54 by mlink             #+#    #+#             */
/*   Updated: 2020/02/21 12:32:49 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

void		*ft_memset(void *destination, int c, size_t len);
char		*ft_strcat(char *destination, const char *append);
char		*ft_strchr(const char *str, int ch);
size_t		ft_strlen(const char *str);
char		*ft_strnew(size_t size);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *destination, const char *source);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
char		*ft_strncpy(char *destination, const char *source, size_t n);
char		*ft_strdup(const char *src);
char		*ft_join_del(char const *s1, char const *s2, int a, int b);

#endif
