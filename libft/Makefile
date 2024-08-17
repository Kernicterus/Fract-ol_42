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

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
MY_SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strnstr.c ft_atoi.c ft_atoi_double.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_putnbr.c

BONUS_FILES = ft_lstnew.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c ft_lstsize.c
		
MY_OBJECTS =  ${MY_SOURCES:.c=.o}

MY_OBJECTS_BONUS =  ${BONUS_FILES:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${MY_OBJECTS}
	${AR} $@ $^

bonus : ${MY_OBJECTS} ${MY_OBJECTS_BONUS}
	${AR} ${NAME} $^

all : ${NAME}

clean :
	rm -rf ${MY_OBJECTS} ${MY_OBJECTS_BONUS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus
