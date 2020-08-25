/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:07:13 by hlourtie          #+#    #+#             */
/*   Updated: 2019/11/23 14:10:56 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		opt(char *s1, char *s2, int option)
{
	if (option == 1)
		free(s1);
	else if (option == 2)
		free(s2);
	else if (option == 3)
	{
		free(s1);
		free(s2);
	}
}

char			*ft_strjoin_free(char *s1, char *s2, int option)
{
	char	*ret;
	size_t	len;
	size_t	i;
	size_t	lentwo;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	ret[len-1] = '\0';
	i = -1;
	len = ft_strlen(s1);
	while (++i < len) 
		ret[i] = s1[i];
	i = -1;
	lentwo = ft_strlen(s2);
	while (++i < lentwo)
		ret[i + len] = s2[i];
	opt(s1, s2, option);
	return (ret);
}
