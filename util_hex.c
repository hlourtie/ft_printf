/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:05:37 by hlourtie          #+#    #+#             */
/*   Updated: 2019/11/29 19:20:32 by hlourtie         ###   ########.fr       */
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

	size = ft_strlen(str);
	if (f->precs > size)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (f->precs - size))))
			return (NULL);
		bzero(ret, (size_t)(f->precs - size));
		ret = (char*)ft_memset(ret, 48, (size_t)(f->precs - size));
		ret[f->precs - size] = '\0';
		ret = ft_strjoin_free(ret, str, 3);
	}
	else
		ret = (f->zero && !f->minus ? manage_zero_hex(str, f) : str);
	return (ret);
}
