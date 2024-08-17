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

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX_PATH = minilibx-linux
LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf
SRC_PATH = src
SRC_PATH_BONUS = src_bonus
OBJ_PATH = obj
OBJ_PATH_BONUS = ${OBJ_PATH}

all : ${NAME}

MY_SOURCES = ${SRC_PATH}/fractol.c \
				${SRC_PATH}/check_arg.c \
				${SRC_PATH}/ft_exit.c \
				${SRC_PATH}/coordinates.c \
				${SRC_PATH}/op_complex.c \
				${SRC_PATH}/events.c \
				${SRC_PATH}/border_tracing.c \
				${SRC_PATH}/border_tracing2.c \
				${SRC_PATH}/display.c \
				${SRC_PATH}/colors.c \
				${SRC_PATH}/mandelbrot.c \
				${SRC_PATH}/julia.c \

MY_SOURCES_BONUS = ${SRC_PATH_BONUS}/fractol_bonus.c \
				${SRC_PATH_BONUS}/check_arg_bonus.c \
				${SRC_PATH_BONUS}/ft_exit_bonus.c \
				${SRC_PATH_BONUS}/coordinates_bonus.c \
				${SRC_PATH_BONUS}/coordinates_minij_bonus.c \
				${SRC_PATH_BONUS}/op_complex_bonus.c \
				${SRC_PATH_BONUS}/events_bonus.c \
				${SRC_PATH_BONUS}/border_tracing_bonus.c \
				${SRC_PATH_BONUS}/border_tracing2_bonus.c \
				${SRC_PATH_BONUS}/display_bonus.c \
				${SRC_PATH_BONUS}/colors_bonus.c \
				${SRC_PATH_BONUS}/color_sets_bonus.c \
				${SRC_PATH_BONUS}/mini_julia_bonus.c \
				${SRC_PATH_BONUS}/mandelbrot_bonus.c \
				${SRC_PATH_BONUS}/julia_bonus.c \
				${SRC_PATH_BONUS}/burning_ship_bonus.c \
				${SRC_PATH_BONUS}/mandelbrot_derivatives_bonus.c

MY_OBJECTS =  ${MY_SOURCES:${SRC_PATH}/%.c=${OBJ_PATH}/%.o}
MY_OBJECTS_BONUS =  ${MY_SOURCES_BONUS:${SRC_PATH_BONUS}/%.c=${OBJ_PATH_BONUS}/%.o}

${OBJ_PATH}/%.o : ${SRC_PATH}/%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} -c $< -o $@
	
${OBJ_PATH_BONUS}/%.o : ${SRC_PATH_BONUS}/%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${MY_OBJECTS}
	make -C ${LIBFT_PATH}
	make -C ${FT_PRINTF_PATH}
	make -C ${MINILIBX_PATH}
	${CC} -o $@ $^ -L ${LIBFT_PATH} -L ${MINILIBX_PATH} -L ${FT_PRINTF_PATH} -lmlx -lXext -lX11 -lft -lftprintf -lm

clean :
	make clean -C ${LIBFT_PATH}
	make clean -C ${MINILIBX_PATH}
	make clean -C ${FT_PRINTF_PATH}
	rm -rf ${OBJ_PATH}

fclean : clean
	make fclean -C ${LIBFT_PATH}
	make fclean -C ${FT_PRINTF_PATH}
	rm -rf ${NAME}

bonus : ${MY_OBJECTS_BONUS}
	make -C ${LIBFT_PATH}
	make -C ${FT_PRINTF_PATH}
	make -C ${MINILIBX_PATH}
	${CC} -o ${NAME} $^ -L ${LIBFT_PATH} -L ${MINILIBX_PATH} -L ${FT_PRINTF_PATH} -lmlx -lXext -lX11 -lft -lftprintf -lm

re : fclean all

.PHONY : all clean fclean re bonus
