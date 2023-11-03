/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:04:41 by luccarva          #+#    #+#             */
/*   Updated: 2023/09/24 19:26:20 by luccarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	options(char *param, va_list	argsptr, int i)
{
	int	c;

	c = 0;
	if (param[i] == 'c')
		c += ft_putchar(va_arg(argsptr, int));
	else if (param[i] == 's')
		ft_putstr(va_arg(argsptr, char *));
	else if (param[i] == 'd')
		ft_putnbr(va_arg(argsptr, int));
	else if (param[i] == 'i')
		ft_putnbr(va_arg(argsptr, int));
	else if (param[i] == 'u')
		ft_putnbr(va_arg(argsptr, unsigned int));
	else if (param[i] == 'x')
		ft_print_hex(va_arg(argsptr, unsigned int), "0123456789abcdef");
	else if (param[i] == 'X')
		ft_print_hex(va_arg(argsptr, unsigned int), "0123456789abcdef");
	else if (param[i] == 'p')
	{
		ft_putstr("0x");
		ft_print_ptr(va_arg(argsptr, unsigned long int), "0123456789abcdef");
	}
	else if (param[i] == '%')
		ft_putchar('%');
	return (c);
}

int	ft_printf(const char	*param, ...)
{
	int		i;
	int		c;
	va_list	argsptr;

	c = 0;
	i = 0;
	va_start(argsptr, param);
	while (param[i])
	{
		if (param[i] == '%')
		{
			c += options((char *)param, argsptr, i + 1);
			i++;
		}
		else
			c += ft_putchar(param[i]);
		i++;
	}
	va_end(argsptr);
	return (c);
}
