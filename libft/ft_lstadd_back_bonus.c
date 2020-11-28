/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:01:58 by hlourtie          #+#    #+#             */
/*   Updated: 2020/11/28 12:56:44 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newer)
{
	t_list *tmp;

	if (newer && alst)
	{
		if (*alst)
		{
			tmp = ft_lstlast(*alst);
			tmp->next = newer;
		}
		else
			*alst = newer;
	}
}
