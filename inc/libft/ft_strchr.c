/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:04:10 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/18 18:48:28 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)s;
	while (ret[i])
	{
		if (ret[i] == (char)c)
			return (ret + i);
		i++;
	}
	if ((char)c == '\0')
		return ((ret + ft_strlen(s)));
	return (NULL);
}
