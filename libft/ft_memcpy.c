/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:36:58 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/20 11:53:25 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (src == dst)
		return (dst);
	if (dst || src)
	{
		while (n)
		{
			((unsigned char*)dst)[n - 1] = ((const unsigned char*)src)[n - 1];
			n--;
		}
	}
	return (dst);
}
