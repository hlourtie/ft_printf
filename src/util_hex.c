/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:05:37 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/29 09:17:41 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*manage_zero_hex(char *str, t_flags *flags)
{
	int		size;
	int		i;
	char	*ret;

	i = 0;
	size = ft_strlen(str);
	if (flags->width > size)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (flags->width + 1))))
			return (NULL);
		ret[flags->width - size] = '\0';
		while (i + size < flags->width)
		{
			ret[i] = '0';
			i++;
		}
		ret = ft_strjoin_free(ret, str, 3);
	}
	else
		ret = str;
	return (ret);
}

/*
**	function to deal with the precision requirements for hexadecimals
*/

char			*check_prec_hex(char *str, t_flags *f)
{
	char	*ret;
	int		size;
	int		i;

	size = ft_strlen(str);
	if (f->precs > size)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (f->precs - size + 1))))
			return (NULL);
		ret[f->precs - size] = '\0';
		i = -1;
		while (++i < (f->precs - size))
			ret[i] = '0';
		ret = ft_strjoin_free(ret, str, 3);
	}
	else
	{
		ret = str;
		if (f->zero && !f->minus)
			ret = manage_zero_hex(str, f);
	}
	return (ret);
}
