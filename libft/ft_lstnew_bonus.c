/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:39:43 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/17 17:09:09 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_list))))
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
