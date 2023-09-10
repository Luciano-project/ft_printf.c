/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:04:41 by luccarva          #+#    #+#             */
/*   Updated: 2023/07/11 05:04:47 by luccarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// Libft functions
void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_print_hex(unsigned int n, char *base)
{
	if (n >= 16)
		ft_print_hex(n / 16, base);
	ft_putchar(base[n % 16]);
}

void	ft_print_ptr(unsigned long long int n, char *base)
{
	if (n >= 16)
		ft_print_ptr(n / 16, base);
	ft_putchar(base[n % 16]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = c - 32;
	return (c);
}

void	options(char *param, va_list	argsptr, int i)
{
	if (param[i] == 'c')
		(va_arg(argsptr, int));
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
	else if (param[i] == 'p'){
		ft_putstr("0x");
		ft_print_ptr(va_arg(argsptr, unsigned int), "0123456789abcdef");
	}
	else if (param[i] == '%')
		ft_putchar('%');
}

int	ft_printf(const char	*param, ...)
{
	va_list	argsptr;
	int		i;

	va_start(argsptr, param);
	i = 0;
	while (param[i])
	{
		if (param[i] == '%')
		{
			options((char *)param, argsptr, i + 1);
			i++;
		}
		else
			ft_putchar(param[i]);
		i++;
	}
	printf("\n");
	va_end(argsptr);
	return (0);
}

int	main()
{
	char *user="faz o L";
	char **name=&user;
	ft_printf("\tHello %p, %s\n", (void *)name, "tumba");
	printf("\tHello %p, %s\n", (void *)name, "tumba");

	ft_putstr("\n(nil)\n");
	return (0);
}
//#################