/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:22:52 by hlourtie          #+#    #+#             */
/*   Updated: 2020/02/01 18:17:30 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

static int		size_result(unsigned long nbr)
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

static char		*hex_this(unsigned long nbr, char c)
{
	int 				count;
	char				*base;
	char				*ret;
	int					i;
	int					res;
	unsigned long		plop;

	plop = nbr;
	count = size_result(plop);
	//printf("count: %d\n", count);
	if (!(ret = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	base = (c == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	i = 0;
	while (i < count)
	{
		res = plop % 16;
		plop /= 16;
		ret[count - (1 + i)] = base[res];
		i++;
	}
	return (ret);
}

int				imprim_p(char **s, t_flags *flags, va_list ap)
{
	unsigned long		ptr;
	char				*str;
	int					len;

	ptr = va_arg(ap, unsigned long);
	str = hex_this(ptr, 'x');
	//printf("str1 : %s\n", str);
	str = check_prec_hex(str, flags);
	//printf("str2 : %s\n", str);
	str = ft_strjoin_free("0x", str, 2);
	//printf("str3 : %s\n", str);
	len = (long)ft_strlen(str);
	if (flags->width > len)
		manage_width(str, flags, (int)len);
	else
		ft_putstr_fd(str, 1);
	s++;
	free(str);
	return (flags->width > len ? flags->width : len);
}

int				imprim_x(char **s, t_flags *flags, va_list ap)
{
	unsigned long	val;
	char			*str;
	int				len;

	val = va_arg(ap, unsigned long);
	if (val == 0 && flags->prec && !flags->precs)
		str = "";
	else
		str = check_prec_hex(hex_this(val, **s), flags);
	//printf("str here: %s\n", str);
	len = ft_strlen(str);
	if (flags->width > len)
		manage_width(str, flags, len);
	else
		ft_putstr_fd(str, 1);
	s++;
	ft_strlen(str) ? free(str) : "";
	return (flags->width > len ? flags->width : len);
}
