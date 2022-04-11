/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:52:48 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/11 23:47:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	set_value(const char *c, long *p_value, int sign, int base)
{
	int	num_value;

	if ('0' <= *c && *c <= '9')
		num_value = *c - '0';
	else if ('a' <= *c && *c <= 'z')
		num_value = *c - 'a' + 10;
	else if ('A' <= *c && *c <= 'Z')
		num_value = *c - 'A' + 10;
	else
		num_value = -1;
	if (num_value < 0 || base <= num_value)
		return (0 == 1);
	*p_value = ((*p_value) * base) + (num_value * sign);
	return (0 == 0);
}

static int	get_base(const char **p_str, const int base)
{
	if (base != 0)
		return (base);
	if ((*p_str)[0] == '0')
	{
		if ((*p_str)[1] == 'x')
		{
			(*p_str)++;
			return (16);
		}
		else
			return (8);
	}
	return (10);
}

static long	ft_strtol(const char *str, char **endptr, int base)
{
	long	sign;
	long	value;

	sign = 1;
	value = 0;
	if (endptr != NULL)
		*endptr = (char *)str;
	if (!((2 <= base && base <= 36) || base == 0))
		return (0);
	while (ft_isspace(*str) && *str != '\0')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str != '+' && !(('a' <= *str && *str <= 'z')
			|| ('A' <= *str && *str <= 'Z') || ('0' <= *str && *str <= '9')))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	base = get_base(&str, base);
	while (set_value(str, &value, sign, base))
		str++;
	if (endptr != NULL)
		*endptr = (char *)str;
	return (value);
}

int	ft_atoi(const char *str)
{
	return (ft_strtol(str, NULL, 10));
}
