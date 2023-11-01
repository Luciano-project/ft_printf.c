/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:04:41 by luccarva          #+#    #+#             */
/*   Updated: 2023/07/11 05:04:47 by luccarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

// Functions
int	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
void	ft_putnbr(int nb);
void	ft_print_hex(unsigned int n, char *base);
void	ft_print_ptr(unsigned long int n, char *base);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
int		ft_toupper(int c);
int		ft_printf(const char	*param, ...);

#endif
