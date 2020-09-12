/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:14:03 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/15 17:34:24 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if ((!dst && !src) || (src == dst))
		return (dst);
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			((unsigned char*)dst)[len] = ((const unsigned char*)src)[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
