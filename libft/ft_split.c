/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:26 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/19 12:17:49 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numbwords(char const *s, char c)
{
	int count;

	count = 1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

static char		**clear_list(char **ret, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		word;
	int		taille;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * (numbwords(s, c) + 1))))
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		taille = 0;
		while (s[i + taille] != c && s[i + taille])
			taille++;
		if (!(ret[word++] = ft_strndup(&s[i], taille)))
			return (clear_list(ret, word));
		i += taille;
	}
	ret[word] = NULL;
	return (ret);
}
