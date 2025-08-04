/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:32:48 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/31 20:36:57 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter(t_list *lst, unsigned int (*f)(void *))
{
	unsigned int	len;

	len = 0;
	if (!lst || !(f))
		return (len);
	while (lst)
	{
		if (lst->content)
			len = len + (f)(lst->content);
		lst = lst->next;
	}
	return (len);
}
