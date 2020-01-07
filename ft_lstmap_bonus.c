/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:03 by hlourtie          #+#    #+#             */
/*   Updated: 2019/10/19 17:05:45 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *temp;

	if (!lst)
		return (NULL);
	temp = ft_lstnew((*f)(lst->content));
	ret = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (ret);
}
