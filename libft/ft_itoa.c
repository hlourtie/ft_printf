/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:27 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/28 13:06:54 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizenum(long n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static size_t	leng(long n)
{
	if (n == 0)
		return (1);
	return (sizenum(n));
}

char			*ft_itoa(long n)
{
	long		num;
	char		*ret;
	size_t		len;

	len = leng(n);
	num = n;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len--] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		num = -1 * (long)n;
	}
	if (num == 0)
		ret[0] = '0';
	while (num)
	{
		ret[len--] = num % 10 + '0';
		num /= 10;
	}
	return (ret);
}
