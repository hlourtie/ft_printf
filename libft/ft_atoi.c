/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:55:28 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/23 17:03:03 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long int	n;
	long int	neg;

	n = 0;
	neg = 0;
	while (*str == '\v' || *str == '\n' || *str == '\r' ||
			*str == '\t' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (!neg && n > 2147483647)
			return (-1);
		else if (n > 2147483648)
			return (0);
		n = n * 10 + (*str - '0');
		str++;
	}
	if (neg) return (-n);
	return (n);
}
