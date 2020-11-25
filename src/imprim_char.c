/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:43:18 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/25 18:20:12 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

/*
**	Prints single characters
*/

int			imprim_c(char **s, t_flags *flags, va_list ap)
{
	int		count;
	char	*c;

	if (!(c = (char*)malloc(sizeof(char) * 2)))
		return (0);
	c[0] = (char)va_arg(ap, int);
	c[1] = '\0';
	count = 1;
	if (flags->width)
		count = flags->width;
	if (flags->width > 1)
	{
		if (c[0] == 0)
			flags->spec = 1;
		manage_width(c, flags, 1);
	}
	else
		ft_putchar_fd(c[0], 1);
	s++;
	free(c);
	return (count);
}

/*
**	checks the precision for the strings
*/

static char	*precis_s(char *str, t_flags *flags)
{
	char *ret;

	ret = str;
	if (flags->prec)
		if (flags->precs < (int)ft_strlen(str) && flags->precs >= 0)
			ret = ft_substr(str, 0, (flags->precs));
	return (ret);
}

/*
**	Prints the strings
*/

int			imprim_s(char **s, t_flags *flags, va_list ap)
{
	char	*str;
	int		count;
	int		size;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	str = precis_s(str, flags);
	size = ft_strlen(str);
	count = size;
	if (flags->width > size)
		count = flags->width;
	if (flags->width > size)
		manage_width(str, flags, size);
	else
		ft_putstr_fd(str, 1);
	if (len != size)
		free(str);
	s++;
	return (count);
}
