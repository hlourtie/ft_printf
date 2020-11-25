/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:08:04 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/25 19:10:44 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	initialise flags
*/

void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->prec = 0;
	flags->precs = 0;
	flags->pres = 0;
	flags->width = 0;
	flags->spec = 0;
}

/*
**	takes a string and deals with a given size of space
*/

void	manage_width(char *str, t_flags *flags, int size)
{
	flags->width -= size;
	if (flags->minus)
	{
		if (flags->spec)
			ft_putchar_fd(0, 1);
		else
			ft_putstr_fd(str, 1);
		while ((flags->width)--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((flags->width)--)
			if (flags->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		if (flags->spec)
			ft_putchar_fd(0, 1);
		else
			ft_putstr_fd(str, 1);
	}
}

/*
**	FT_SIZENUM 
*/

long	ft_sn(long nbr, long pres)
{
	long count;

	count = 0;
	if (!pres && (nbr < 0))
		count = 1;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

/*
**	Manages special cases for decimals
*/

void	special_d(char *str, t_flags *flags)
{
	if(flags->zero && str[0]== '-'){
		str[0] = '0';
		ft_putchar_fd('-', 1);
		(flags->width)--;
	}
	while ((flags->width)--)
			if (flags->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		if (flags->spec)
			ft_putchar_fd(0, 1);
		else
			ft_putstr_fd(str, 1);
}

/*
**	Manages the return value following the precision rules
*/

char	*manage_return(t_flags *f, long nbr){
	if (f->zero && !f->minus && !f->prec)
		return (manage_zero(nbr, f));
	return (ft_itoa(nbr));
}