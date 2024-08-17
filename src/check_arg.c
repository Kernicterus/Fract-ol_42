/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:54 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 18:50:22 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_julia(int argc, char **argv, t_display *ptr)
{
	if (argc > 4)
		ft_error();
	if (argc == 2)
	{
		(ptr->c).x = 0;
		(ptr->c).y = 0;
	}
	else if (argc == 3)
	{
		(ptr->c).x = ft_atoi_double(argv[2]);
		(ptr->c).y = 0;
	}
	else if (argc == 4)
	{
		(ptr->c).x = ft_atoi_double(argv[2]);
		(ptr->c).y = ft_atoi_double(argv[3]);
	}
}

static void	check_mandelbrot(int argc)
{
	if (argc != 2)
		ft_error();
}

void	check_arg(int argc, char **argv, t_display *ptr)
{
	if (argc == 1)
		ft_error();
	if (ft_strncmp("J", argv[1], 2) == 0)
		check_julia(argc, argv, ptr);
	else if (ft_strncmp("M", argv[1], 2) == 0)
		check_mandelbrot(argc);
	else
		ft_error();
}
