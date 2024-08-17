# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nledent <nledent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 11:13:31 by nledent          #+#    #+#              #
#    Updated: 2023/11/03 16:44:31 by nledent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

MY_SOURCES = ft_printf.c ft_print_to_screen.c ft_putadress_hexa_printf.c \
		ft_putchar_printf.c ft_putnbr_printf.c ft_putnbr_hexa_printf.c \
		ft_putnbr_hexa_maj_printf.c ft_putnbr_u_printf.c ft_putstr_printf.c \
		ft_strchr_printf.c ft_strlen_printf.c 
	
MY_OBJECTS =  ${MY_SOURCES:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${MY_OBJECTS}
	${AR} $@ $^

all : ${NAME}

clean :
	rm -rf ${MY_OBJECTS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
