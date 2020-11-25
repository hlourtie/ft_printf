/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:34:58 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/25 19:10:38 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	compares the character and gets the right printing sequence
*/

int		ft_write(char **s, t_flags *flags, va_list ap)
{
	int count;
	if (**s == 'c')
		count = imprim_c(s, flags, ap);
	else if (**s == 's')
		count = imprim_s(s, flags, ap);
	else if (**s == 'p')
		count = imprim_p(s, flags, ap);
	else if (**s == 'd' || **s == 'i')
		count = imprim_d(s, flags, ap);
	else if (**s == 'u')
		count = imprim_u(s, flags, ap);
	else if (**s == 'x' || **s == 'X')
		count = imprim_x(s, flags, ap);
	else if (**s == '%')
		count = imprim_perc(s, flags);
	else
		return (0);
	return (count);
}

/*
**	handles the general flags minus and zero
*/

int		handle_gen(char **s, t_flags *flags)
{ 
	if (**s == '-')
		flags->minus = 1;
	else if (**s == '0')
		flags->zero = 1;
	else
		return (0);
	return (1);
}

/*
** handles the general width of what is supposed to be printed
*/

int		handle_width(char **s, t_flags *flags, va_list ap)
{
	int width;

	if ((ft_atoi(*s) > 0 || **s == '*') && flags->width == 0)
	{
		if (**s == '*')
		{
			width = va_arg(ap, int);
			if (width < 0)
				flags->minus = 1;
			flags->width = width;
			if (width < 0) flags->width = -width;
		}
		else
		{
			flags->width = ft_atoi(*s);
			*s += ft_sn((long)flags->width, 0) - 1;
		}
		return (1);
	}
	return (0);
}

/*
**	sets the precision in case there is a precision flag
*/

static void	set_precision( int temp, char **s, t_flags *flags, va_list ap)
{
	int num;

	num = 0;
	flags->prec = 1;
		flags->zero = 0;
		(*s)++;
		if (**s == '*')
		{
			num = va_arg(ap, int);
			flags->zero = 0;
			if (num < 0 && temp) 
				flags->zero = 1;
			flags->precs = num;
		}
		else
		{
			if (!ft_isdigit(**s))
				flags->pres = 1;
			flags->precs = ft_atoi(*s);
			*s += ft_sn((long)flags->precs, 0) - 1;
		}
}

/*
** Handle the precision flag and then adds the right value we need
*/

int		handle_prec(char **s, t_flags *flags, va_list ap)
{
	int temp;

	temp  = 0;
	if (flags->zero)
		temp = 1;
	if (**s == '.')
	{
		set_precision(temp, s, flags, ap);
		return (1);
	}
	return (0);
}