/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:52:18 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/11 23:34:52 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			pos = 0;
			while (needle[pos] != '\0'
				&& len > pos && haystack[pos] == needle[pos])
				pos++;
			if (needle[pos] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
