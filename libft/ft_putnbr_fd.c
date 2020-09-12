/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:30:52 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/07 15:36:39 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	a;
	int			u;
	char		c;

	a = n;
	if (a < 0)
	{
		write(fd, "-", 1);
		a = a * (-1);
	}
	u = a / 10;
	if (u >= 1)
		ft_putnbr_fd(u, fd);
	c = (a % 10) + '0';
	write(fd, &c, 1);
}
