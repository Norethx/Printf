/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:38:52 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/21 15:32:09 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux_del;

	aux = *lst;
	if (*lst == ((void *)0) || del == ((void *)0))
		return ;
	while (aux->next != ((void *)0))
	{
		aux_del = aux;
		aux = aux->next;
		ft_lstdelone(aux_del, (del));
	}
	ft_lstdelone(aux, (del));
	*lst = ((void *)0);
	return ;
}
