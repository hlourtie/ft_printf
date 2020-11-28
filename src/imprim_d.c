/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:47:20 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/28 12:46:59 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				imprim_d(char **s, t_flags *flags, va_list ap)
{
	int		count;
	long	var;
	int		size;
	char	*ret;

	var = (long)va_arg(ap, int);
	ret = check_prec(var, flags);
	if (!var && flags->prec && !flags->precs)
		ret = "";
	size = ft_strlen(ret);
	count = size;
	if (flags->width > size)
		count = flags->width;
	if (flags->width > size)
		manage_width_d(ret, flags, size);
	else
		ft_putstr_fd(ret, 1);
	s++;
	if (ft_strlen(ret))
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
	if (var < 0)
		var = 4294967296 + var;
	ret = check_prec(var, flags);
	if (!var && flags->prec && !flags->precs)
		ret = "";
	size = ft_strlen(ret);
	count = size;
	if (flags->width > size)
		count = flags->width;
	if (flags->width > size)
		manage_width(ret, flags, size);
	else
		ft_putstr_fd(ret, 1);
	s++;
	if (ft_strlen(ret))
		free(ret);
	return (count);
}
