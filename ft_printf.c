/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:43:30 by hlourtie          #+#    #+#             */
/*   Updated: 2019/11/11 11:09:28 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*s;
	va_list	ap;
	int		count;

	s = (char*)format;
	count = 0;
	va_start(ap, format);
	while (*s)
		if (*s == '%')
		{
			s++;
			count += handle_flags(&s, ap);
			s++;
		}
		else
		{
			write(1, s++, 1);
			count++;
		}
	va_end(ap);
	return (count);
}
