/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:17:07 by luccarva          #+#    #+#             */
/*   Updated: 2023/11/01 20:19:08 by luccarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char *user="ola\n";
	char **name=&user;
	ft_printf("\tHello %p, %s\n", (void *)name, "tumba");
	printf("\tHello %p, %s\n", (void *)name, "tumba");

	return (0);
}
