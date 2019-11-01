/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:28:16 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/30 21:29:22 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./inc/libft/libft.h"
/*
typedef struct	v_flags{
	int precision;
}				t_flags;

int ft_sizenum(int nbr, int pres)
{
	int count;

		count = ((!pres && (nbr < 0)) ? 1 : 0 );	
	while(nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char *check_precision(int nbr, t_flags *flags)
{
	char *temp;
	int tmpn;
	char *ret;
	
	if (flags->precision > ft_sizenum(nbr, 1))
	{
		temp = (nbr < 0 ? ft_itoa(-nbr) : ft_itoa(nbr));
		if (!(ret = (char *) malloc(sizeof(char) *  (flags->precision - ft_sizenum(nbr,1)))))
			return (NULL);
		bzero(ret, (size_t) (flags->precision - ft_sizenum(nbr,1)));
		ret = (char*)ft_memset(ret, 48, (size_t) (flags->precision - ft_sizenum(nbr,1)));
		ret = ft_strjoin_free(ret, temp, 2);
		if (nbr < 0)
		{
			if (!(temp = (char *)malloc(sizeof(char) * 2)))
		 		return (NULL);
			temp[0] = '-';
			temp[1] = '\0';
			printf("this is temp %s\nthis is ret %s\n", temp, ret);
			ret = ft_strjoin_free(temp, ret, 2);
		}
	}
	else 
		ret = ft_itoa(nbr);
	return (ret);
}*/

int size_result(long int nbr)
{
	int count;

	count = 0;
	while (nbr)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

char *hex_this(long nbr, char c, int *count)
{
	char *base;
	char *ret;
	int i;
	int res;
    long int plop;

	plop = (nbr < 0 ? 4294967296 + nbr : nbr);
	*count = size_result(plop);
	if(!(base = (char *)malloc(sizeof(char) * 17)) || !(ret = (char *)malloc(sizeof(char) * (*count + 1))))
		return (NULL);
	base = (c == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	i = 0;
	while (i < *count)
	{
		res = plop % 16;
		plop /= 16;
		ret[*count -1 - i] = base[res];
        i++;
	}
	ret[*count] = '\0';
	return (ret);
}
int main()
{ 	int a = -9;
	int *b = &a;
	int count;
	
	/*t_flags flag;
	flag.precision = 0;
	char *ret;
	ret = check_precision(a, &flag);
    printf("%s\n", ret);*/
	printf("%s\n", hex_this((long) b, 'x', &count));
	printf("%p\n", (void*) b);
}