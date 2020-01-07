/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:22:52 by hlourtie          #+#    #+#             */
/*   Updated: 2019/11/29 19:39:43 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

static int		size_result(long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

static char		*hex_this(long nbr, char c, int *count)
{
	char		*base;
	char		*ret;
	int			i;
	int			res;
	long		plop;

	plop = (nbr < 0 && nbr > -4294967296 ? 4294967296 + nbr : nbr);
	*count = size_result(plop);
	if (!(ret = (char *)malloc(sizeof(char) * (*count + 1))))
		return (NULL);
	base = (c == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	i = 0;
	while (i < *count)
	{
		res = plop % 16;
		plop /= 16;
		ret[*count - 1 - i] = base[res];
		i++;
	}
	ret[*count] = '\0';
	return (ret);
}

int				imprim_p(char **s, t_flags *flags, va_list ap)
{
	int			count;
	long		ptr;
	char		*str;

	ptr = (long)va_arg(ap, void *);
	str = hex_this(ptr, 'x', &count);
	str = check_prec_hex(str, flags);
	str = ft_strjoin_free("0x", str, 2);
	ptr = (long)ft_strlen(str);
	count = flags->width > ptr ? flags->width : ptr;
	if (flags->width > ptr)
		manage_width(str, flags, (int)ptr);
	else
		ft_putstr_fd(str, 1);
	s++;
	free(str);
	return (count);
}

int				imprim_x(char **s, t_flags *flags, va_list ap)
{
	long	val;
	char	*str;
	int		count;

	val = (long)va_arg(ap, int);
	str = hex_this(val, **s, &count);
	str = check_prec_hex(str, flags);
	val = ft_strlen(str);
	count = flags->width > val ? flags->width : val;
	if (flags->width > val)
		manage_width(str, flags, val);
	else
		ft_putstr_fd(str, 1);
	s++;
	free(str);
	return (count);
}
