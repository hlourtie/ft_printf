/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 07:37:34 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/19 14:57:28 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	j;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (lendst >= size)
		return (size + lensrc);
	lensrc += lendst;
	j = 0;
	while (src[j] != '\0' && lendst < size - 1 && dst != src)
	{
		dst[lendst] = src[j];
		lendst++;
		j++;
	}
	dst[lendst] = '\0';
	return (lensrc);
}
