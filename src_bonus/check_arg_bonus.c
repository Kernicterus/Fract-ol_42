/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:54 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 13:23:45 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	ptr->offset_x = 0;
	ptr->offset_y = 0;
}

static void	check_mandelbrot(int argc, t_display *ptr)
{
	if (argc > 2)
		ft_error();
	else
	{
		ptr->offset_x = 0;
		ptr->offset_y = 0;
	}
}

static void	check_mandelbrot_d(int argc, char **argv, t_display *p)
{
	if (argc > 4)
		ft_error();
	(p->power) = 3;
	(p->c).x = 0;
	(p->c).y = 0;
	p->inverted = 0;
	if (argc >= 3)
	{
		(p->power) = ft_atoi_double(argv[2]);
		if (p->power > 50 || p->power < -15 || p->power == 0 || p->power == -1)
			ft_error();
	}
	if (argc == 4)
	{
		if (argv[3][0] == 'I')
			p->inverted = 1;
		else
			ft_error();
	}
	p->offset_x = 0;
	p->offset_y = 0;
}

void	check_arg(int argc, char **argv, t_display *ptr)
{
	if (argc == 1)
		ft_error();
	if (ft_strncmp("J", argv[1], 2) == 0)
		check_julia(argc, argv, ptr);
	else if (ft_strncmp("M", argv[1], 2) == 0)
		check_mandelbrot(argc, ptr);
	else if (ft_strncmp("B", argv[1], 2) == 0)
		check_mandelbrot(argc, ptr);
	else if (ft_strncmp("D", argv[1], 2) == 0)
		check_mandelbrot_d(argc, argv, ptr);
	else
		ft_error();
}

void	put_fractal(t_complex *pixel, t_display *ptr, int **tab_pixels)
{
	if (ptr->fractal == 'M')
		ft_mandelbrot(pixel, ptr, tab_pixels);
	else if (ptr->fractal == 'J')
		ft_julia(pixel, ptr, tab_pixels);
	else if (ptr->fractal == 'D')
		ft_mandelbrot_d(pixel, ptr, tab_pixels);
}
