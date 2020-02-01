/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:28:16 by hlourtie          #+#    #+#             */
/*   Updated: 2020/02/01 17:55:22 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./inc/ft_printf.h"
#include <limits.h>


int main()
{ 	
	ft_printf("%10.2i\n", 0);
	ft_printf("%10.2i\n", 0);
	printf("%02.0i\n", 0);
	printf("%02.0d\n", 0);


	//system("leaks a.out");
	return 0;
}