/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprim_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:52:27 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/29 09:48:37 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*manage_zero_perc(t_flags *flags)
{
	int		i;
	char	*ret;

	i = 0;
	if (flags->width > 1)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (flags->width + 1))))
			return (NULL);
		ret[flags->width - 1] = '\0';
		while (i + 1 < flags->width)
		{
			ret[i] = '0';
			i++;
		}
		ret = ft_strjoin_free(ret, "%", 1);
	}
	else
		ret = "%";
	return (ret);
}

int				imprim_perc(char **s, t_flags *flags)
{
	int		size;
	char	*str;
	int		count;

	if ((flags->zero && !flags->minus) || (flags->prec && !flags->minus))
		str = manage_zero_perc(flags);
	else
		str = "%";
	size = ft_strlen(str);
	count = size;
	if (flags->width > size)
		count = flags->width;
	if (flags->width > size)
		manage_width(str, flags, size);
	else
		ft_putstr_fd(str, 1);
	s++;
	if (size != 1)
		free(str); 
	return (count);
}
