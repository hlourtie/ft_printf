/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:47:20 by hlourtie          #+#    #+#             */
/*   Updated: 2019/11/29 19:45:38 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**	Places the zeros where they need to be
*/

static char		*manage_zero(long nbr, t_flags *flags)
{
	long size;
	long i;
	char *ret;

	i = (nbr < 0 ? 1 : 0);
	size = ft_sn(nbr, 1);
	if (flags->width > size + 1)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (flags->width + 1))))
			return (NULL);
		ret[0] = (nbr < 0 ? '-' : '0');
		if (ret[0] == '-')
			nbr = -nbr;
		while (i + size + 1 <= flags->width)
		{
			ret[i] = '0';
			i++;
		}
		ret[i] = '\0';
		ret = ft_strjoin_free(ret, ft_itoa(nbr), 3);
	}
	else
		ret = ft_itoa(nbr);
	return (ret);
}

/*
**	function to deal with the precision requirements
*/

static char		*check_prec(long nbr, t_flags *f)
{
	char *temp;
	char *ret;

	if (f->precs > ft_sn(nbr, 1))
	{
		temp = (nbr < 0 ? ft_itoa(-nbr) : ft_itoa(nbr));
		if (!(ret = (char *)malloc(sizeof(char) * (f->precs - ft_sn(nbr, 1)))))
			return (NULL);
		bzero(ret, (size_t)(f->precs - ft_sn(nbr, 1)));
		ret = (char*)ft_memset(ret, 48, (size_t)(f->precs - ft_sn(nbr, 1)));
		ret[(f->precs - ft_sn(nbr, 1))] = '\0';
		ret = ft_strjoin_free(ret, temp, 3);
		if (nbr < 0)
		{
			if (!(temp = (char *)malloc(sizeof(char) * 2)))
				return (NULL);
			temp[0] = '-';
			temp[1] = '\0';
			ret = ft_strjoin_free(temp, ret, 3);
		}
	}
	else
		ret = (f->zero && !f->minus && !f->prec ? manage_zero(nbr, f)
			: ft_itoa(nbr));
	return (ret);
}

/*
**	Prints the ints and Doubles
*/

int				imprim_d(char **s, t_flags *flags, va_list ap)
{
	int		count;
	long	var;
	int		size;
	char	*ret;

	var = (long)va_arg(ap, int);
	ret = check_prec(var, flags);
	size = ft_strlen(ret);
	count = flags->width > size ? flags->width : size;
	if (flags->width > size)
		manage_width(ret, flags, size);
	else
		ft_putstr_fd(ret, 1);
	s++;
	free(ret);
	return (count);
}

/*
**	Print the unsigned ints.
*/

int				imprim_u(char **s, t_flags *flags, va_list ap)
{
	int		count;
	long	var;
	int		size;
	char	*ret;

	var = (long)va_arg(ap, unsigned int);
	var = (var < 0 ? 4294967296 + var : var);
	ret = check_prec(var, flags);
	size = ft_strlen(ret);
	count = flags->width > size ? flags->width : size;
	if (flags->width > size)
		manage_width(ret, flags, size);
	else
		ft_putstr_fd(ret, 1);
	s++;
	free(ret);
	return (count);
}
