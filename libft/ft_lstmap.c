/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:48:25 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/25 11:35:10 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst || !f || !del)
		return ((void *)0);
	new = ft_lstnew((f)(lst->content));
	if (!new)
		return ((void *)0);
	head = new;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew((f)(lst->content)));
		if (!new)
		{
			ft_lstclear(&head, (del));
			return ((void *)0);
		}
		lst = lst->next;
	}
	return (head);
}
