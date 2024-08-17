/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:38:19 by nico              #+#    #+#             */
/*   Updated: 2024/01/16 13:15:31 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	start_tracing(int x, int y, int **tab_pixels, t_display *ptr)
{
	t_complex	pixel;

	if (tab_pixels[x][y] == -1)
	{
		pixel.x = x;
		pixel.y = y;
		if (ptr->fractal == 'M')
			ft_mandelbrot(&pixel, ptr, tab_pixels);
		else if (ptr->fractal == 'J')
			ft_julia(&pixel, ptr, tab_pixels);
	}
	if (tab_pixels[x][y] == 0)
	{
		border_tracing(x - 1, y, ptr, tab_pixels);
		return (0);
	}
	return (1);
}

static void	reach_borders_horiz(int **tab_pixels, t_display *ptr)
{
	int			x;
	int			y;

	y = 0;
	while (y < ptr->win_h)
	{
		x = 0;
		while (x < ptr->win_w)
		{
			if (start_tracing(x, y, tab_pixels, ptr) == 0)
				break ;
			x++;
		}
		x = ptr->win_w - 1;
		while (x >= 0)
		{
			if (start_tracing(x, y, tab_pixels, ptr) == 0)
				break ;
			x--;
		}
		y++;
	}
}

static void	reach_borders_vertical(int **tab_pixels, t_display *ptr)
{
	int			x;
	int			y;

	x = 0;
	while (x < ptr->win_w)
	{
		y = ptr->win_h - 1;
		while (y >= 0)
		{
			if (start_tracing(x, y, tab_pixels, ptr) == 0)
				break ;
			y--;
		}
		y = 0;
		while (y < ptr->win_h)
		{
			if (start_tracing(x, y, tab_pixels, ptr) == 0)
				break ;
			y++;
		}
		x++;
	}
}

static int	look_for_colored(t_complex pixel, int **tab_pixels, t_display *ptr)
{
	if (tab_pixels[(int)pixel.x][(int)pixel.y] == -1
		&& is_there_color_around(pixel.x, pixel.y, ptr, tab_pixels) == 1)
	{
		if (ptr->fractal == 'M')
			ft_mandelbrot(&pixel, ptr, tab_pixels);
		else if (ptr->fractal == 'J')
			ft_julia(&pixel, ptr, tab_pixels);
		return (0);
	}
	return (1);
}

void	fractol_borders(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;
	int			finish;

	reach_borders_horiz(tab_pixels, ptr);
	reach_borders_vertical(tab_pixels, ptr);
	finish = 0;
	while (finish == 0)
	{
		finish = 1;
		pixel.y = 0;
		while (pixel.y < ptr->win_h)
		{
			pixel.x = 0;
			while (pixel.x < ptr->win_w)
			{
				if (look_for_colored(pixel, tab_pixels, ptr) == 0)
					finish = 0;
				(pixel.x)++;
			}
			(pixel.y)++;
		}
	}
	fill_rest(ptr, tab_pixels, rgb_to_int(0, 0, 0));
}
