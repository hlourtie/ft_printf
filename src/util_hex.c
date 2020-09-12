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
#include <stdio.h>

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
void printFlags(t_flags *flags){
	printf("zero: %i\n",flags->zero);
	printf("minus: %i\n",flags->minus);
	printf("prec: %i\n",flags->prec);
	printf("precs: %i\n",flags->precs);
	printf("pres: %i\n",flags->pres);
	printf("width: %i\n",flags->width);
	printf("spec: %i\n",flags->spec);
}

// char *thisshit(int x)
// {
// 	int i;
// 	char *ret;

// 	if (!(ret = (char *)malloc(sizeof(char) * x )))
// 			return (NULL);
// 	i = 0;
// 	while(i<x){
// 		ret[i] = '0'
// 	}

// }

char			*check_prec_hex(char *str, t_flags *f)
{
	char	*ret;
	int		size;
	int		i;

	//printFlags(f);
	size = ft_strlen(str);
	// printf("str: %s and size %d\n", str,size);
	if (f->precs > size)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (f->precs - size))))
			return (NULL);
		printf("before %s\n", str);
		ret[f->precs - size] = '\0';
		printf("after ret set %s\n", str);
		//ft_bzero(ret, (size_t)(f->precs - size));
		i = -1;
		while (++i < (f->precs - size))
		{
			printf("after %d %s\n", i,str);
			ret[i] = '\0';
		}
		printf("after %s\n", str);
		// problem is in this mem set
		i = -1;
		while (++i < (f->precs - size))
			ret[i] = '0';
		//ret[f->precs - size] = '\0';
		//printf("%s\n", str);
		ret = ft_strjoin_free(ret, str, 3);
		//printf("%s\n", ret);
	}
	else
		ret = (f->zero && !f->minus ? manage_zero_hex(str, f) : str);
	return (ret);
}
