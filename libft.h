/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:37:46 by tetsu             #+#    #+#             */
/*   Updated: 2022/04/10 16:52:03 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Dependency:
// - size_t
# include <stddef.h>

// Libft-01
int		ft_toupper(int c);
int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2);

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strstr(const char *haystack, const char *needle);

int		ft_atoi(const char *str);

#endif
