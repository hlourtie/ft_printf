/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_absolute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:30:30 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/28 13:01:05 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_absolute(long nbr)
{
	if (nbr >= 0)
		return (ft_itoa(nbr));
	else
		return (ft_itoa(-nbr));
}
