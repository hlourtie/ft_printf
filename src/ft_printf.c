/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:43:30 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/25 19:10:13 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	handles the flags and starts the writing process
*/

int		handle_flags(char **s, va_list ap)
{
	int		count;
	t_flags flags;

	count = 0;
	init_flags(&flags);
	while (handle_gen(s, &flags) || handle_width(s, &flags, ap)
			|| handle_prec(s, &flags, ap))
	{
		if (flags.pres)
			continue ;
		(*s)++;
		if (flags.precs && ft_atoi(*s))
			(*s)++;
	}
	count = ft_write(s, &flags, ap);
	return (count);
}

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
