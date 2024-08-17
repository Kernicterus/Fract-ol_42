/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracing2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:38:19 by nico              #+#    #+#             */
/*   Updated: 2024/01/18 12:15:30 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	start_tracing(int x, int y, int **tab_pixels, t_display *ptr)
{
	t_complex	pixel;

	if (tab_pixels[x][y] == -1)
	{
		pixel.x = x;
		pixel.y = y;
		put_fractal(&pixel, ptr, tab_pixels);
	}
	if (tab_pixels[x][y] == 0)
	{
		border_tracing(x - 1, y, ptr, tab_pixels);
		return (0);
	}
	return (1);
}

void	reach_borders_x(int **tab_px, t_display *ptr, int x, int y)
{
	int	startx;

	startx = x;
	while (y < ptr->win_h - 1)
	{
		x = startx;
		while (x < ptr->win_w - 1)
		{
			if (start_tracing(x, y, tab_px, ptr) == 0)
				break ;
			x++;
		}
		x = ptr->win_w - startx - 1;
		while (x >= 0)
		{
			if (start_tracing(x, y, tab_px, ptr) == 0)
				break ;
			x--;
		}
		y++;
	}
}

void	reach_borders_y(int **tab_px, t_display *ptr, int x, int y)
{
	int	starty;

	starty = y;
	while (x < ptr->win_w - 1)
	{
		y = ptr->win_h - starty - 1;
		while (y >= 0)
		{
			if (start_tracing(x, y, tab_px, ptr) == 0)
				break ;
			y--;
		}
		y = starty;
		while (y < ptr->win_h - 1)
		{
			if (start_tracing(x, y, tab_px, ptr) == 0)
				break ;
			y++;
		}
		x++;
	}
}

int	look_for_colored(t_complex pixel, int **tab_pixels, t_display *ptr)
{
	if (tab_pixels[(int)pixel.x][(int)pixel.y] == -1
		&& is_there_color_around(pixel.x, pixel.y, ptr, tab_pixels) == 1)
	{
		put_fractal(&pixel, ptr, tab_pixels);
		return (0);
	}
	return (1);
}

void	fractol_borders(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;
	int			finish;

	reach_borders_x(tab_pixels, ptr, 0, 0);
	reach_borders_y(tab_pixels, ptr, 0, 0);
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
