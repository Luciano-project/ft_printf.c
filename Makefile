# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccarva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 18:48:17 by luccarva          #+#    #+#              #
#    Updated: 2023/11/01 18:48:22 by luccarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
		
SRCS =  ft_printf.c	ft_printf_utils.c	ft_lib_func.c
OBJS	:= ${SRCS:.c=.o}
CC		:= gcc
RM		:= /bin/rm -f
CFLAGS	:= -Wall -Wextra -Werror
CL		:= ar -rc
RL		:= ar -s

${NAME}: ${OBJS}
	${CL} ${NAME} ${OBJS}
	${RL} ${NAME}
	echo 'libftprintf is ready'

all: ${NAME}

clean:
	${RM} ${OBJS}
	echo 'Objects removed'

fclean: clean
	${RM} ${NAME}
	echo 'Static library removed'

re: fclean all

norm:
	echo 'Running Norminette'
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h
