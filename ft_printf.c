/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:51:10 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/07/24 20:55:00 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char			*ft_printf_digit(void *v_print, char c);
static void			ft_putstr_lst(void *s);
static unsigned int	ft_len_printf(t_list **lst);

int	ft_printf(const char *str, ...)
{
	t_list			*new;
	void			*ls_arg;
	va_list			args;
	int				i;
	int				flag;
	unsigned int	len_printf;

	new = NULL;
	i = 0;
	va_start(args, str);
	ls_arg = va_arg(args, void *);
	flag = 0;
	while (str[i])
	{
		if (str[i++] == '%' && str[i] != 0)
		{
			ft_lstadd_back(&new, ft_lstnew(ft_substr(str, i - 1 - flag, flag)));
			if (ft_strchr("cdiuxXps%", str[i]) && str[i] != 0)
			{
				if (ft_strchr("cdiuxXps", str[i]))
					ft_lstadd_back(&new, ft_lstnew(ft_printf_digit(ls_arg,
								str[i])));
				else if (ft_strchr("%", str[i]))
					ft_lstadd_back(&new, ft_lstnew(ft_strdup("%")));
				if (str[i] != '%')
					ls_arg = va_arg(args, void *);
			}
			else
				write(2, &"Invalid type", 12);
			flag = -1;
			i++;
		}
		flag++;
	}
	if (flag > 0)
		ft_lstadd_back(&new, ft_lstnew(ft_substr(str, i - flag, flag)));
	ft_lstiter(new, &ft_putstr_lst);
	len_printf = ft_len_printf(&new);
	ft_lstclear(&new, &free);
	va_end(args);
	return (len_printf);
}

static void	ft_putstr_lst(void *s)
{
	int	i;

	i = 0;
	while (((char *)s)[i] != '\0')
		ft_putchar_fd(((char *)s)[i++], 1);
}

static unsigned int	ft_len_printf(t_list **lst)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = *lst;
	while (aux)
	{
		i += ft_strlen((char *)aux->content);
		aux = aux->next;
	}
	return (i);
}

static char	*ft_printf_digit(void *v_print, char c)
{
	if (c == 'd')
		return (ft_lltoa((long long)v_print));
	if (c == 'i')
		return (ft_itoa((long long)v_print));
	if (c == 'u')
		return (ft_Uitoa((long long)v_print));
	if (c == 'x')
		return (ft_Uitoa_base((long long)v_print, "0123456789abcdef"));
	if (c == 'X')
		return (ft_Uitoa_base((long long)v_print, "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_Ulltoa_base((unsigned long long)&*v_print,
				"0123456789abcdef"));
	if (c == 's')
		return ((char *)v_print);
	if (c == 'c')
		return ((char *)ft_memset(ft_calloc(2, 1), (unsigned long long)v_print,
				1));
	return ("erro");
}

// int	main(void)
// {
// 	int	i;
// 	int	j;
// 	int	h;

// 	i = 1;
// 	// char e[] = "dffewfw";
// 	// int *ptri = &i;
// 	j = ft_printf("ihfu%d\n   aaaaa%%%%%i%%%p%% %d%p", 2, 2, &i, 1000, &i);
// 	h = printf("\nihfu%d\n   aaaaa%%%%%i%%%p%% %d%p", 2, 2, &i, 1000,&i);
// 	// j = ft_printf(" %x ", -100);
// 	// h = printf(" %x ", -100);
// 	ft_printf("%d%d", j, h);
// }

// numerico("cdiuxX")
// memoria(p)
// string(s)
// char(%)

// Você terá que implementar as seguintes conversões:
// • %c Imprime um único caractere.
// • %s Imprime uma string (conforme definido pela convenção comum do C).
// • %p O endereço do ponteiro void * deve ser impresso em formato hexadecimal.
// • %d Imprime um número decimal (base 10).
// • %i Imprime um inteiro em base 10.
// • %u Imprime um número decimal (base 10) sem sinal.
// • %x Imprime um número em formato hexadecimal (base 16) em minúsculas.
// • %X Imprime um número em formato hexadecimal (base 16) em maiúsculas.
// • %% Imprime um sinal de porcentagem.
