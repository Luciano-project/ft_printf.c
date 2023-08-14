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
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *param, ...)
{
	va_list	argsptr;
	va_start(argsptr, param);

	for (int i = 0; i < *param; i++)
	{
		printf("%s\n", va_arg(argsptr, char *));
	}
	va_end(argsptr);

	return (0);
}

int	main(void)
{
	ft_printf("Hello %s\n", "World");
	return (0);
}