/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:51:10 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/23 19:51:23 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	void	*ls_arg;
	va_list	args;
	int		i;
	char *flags = (char *)"#%";

	i = 0;
	va_start(args, str);
	ls_arg = va_arg(args, void *);
	while (str[i])
	{
		if (str[i++] == '%' && str[i] != 0)
		{
			if(str[i] == 'd' && str[i] != 0)
				write(1, &"pao", 3);
		}
	}
	return (0);
}

int main(void)
{
	ft_printf("ihfu%d");
}
