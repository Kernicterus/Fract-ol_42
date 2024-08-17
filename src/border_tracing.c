/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:38:19 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 20:38:26 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_inside(int x, int y, t_display *ptr)
{
	if (x >= ptr->win_w || y >= ptr->win_h)
		return (0);
	else if (x < 0 || y < 0)
		return (0);
	else
		return (1);
}

int	is_there_color_around(int x, int y, t_display *ptr, int **tab_pixels)
{
	int	x_next;
	int	y_next;	

	x_next = x + 2;
	while (--(x_next) >= x - 1)
	{
		y_next = y + 2;
		while (--(y_next) >= y - 1)
		{
			if (is_inside(x_next, y_next, ptr) == 1
				&& (x_next != x || y_next != y))
			{
				if (tab_pixels[x_next][y_next] > 0)
					return (1);
			}
		}
	}
	return (0);
}

static int	is_there_unk_around(int x, int y, t_display *ptr, int **tab_pixels)
{
	int	x_next;
	int	y_next;	

	x_next = x + 2;
	while (--(x_next) >= x - 1)
	{
		y_next = y + 2;
		while (--(y_next) >= y - 1)
		{
			if (is_inside(x_next, y_next, ptr) == 1
				&& (x_next != x || y_next != y))
			{
				if (tab_pixels[x_next][y_next] == -1)
					return (1);
			}
		}
	}
	return (0);
}

static int	is_there_black_around(int x, int y, t_display *ptr, int **tab_pix)
{
	t_complex	pix;
	int			black;

	pix.x = x + 2;
	black = 0;
	while (--(pix.x) >= x - 1)
	{
		pix.y = y + 2;
		while (--(pix.y) >= y - 1)
		{
			if (is_inside(pix.x, pix.y, ptr) == 1 && (pix.x != x || pix.y != y))
			{
				if (tab_pix[(int)pix.x][(int)pix.y] == -1
					&& (ptr->fractal == 'M'))
					ft_mandelbrot(&pix, ptr, tab_pix);
				else if (tab_pix[(int)pix.x][(int)pix.y] == -1
					&& (ptr->fractal == 'J'))
					ft_julia(&pix, ptr, tab_pix);
				if (tab_pix[(int)pix.x][(int)pix.y] == 0)
					black = 1;
			}
		}
	}
	return (black);
}

int	border_tracing(int x, int y, t_display *ptr, int **tab_pixels)
{
	int	x_next;
	int	y_next;

	if (is_there_unk_around(x, y, ptr, tab_pixels) == 1
		&& is_there_black_around(x, y, ptr, tab_pixels) == 1)
	{
		x_next = x + 2;
		while (--(x_next) >= x - 1)
		{
			y_next = y + 2;
			while (--(y_next) >= y - 1)
			{
				if (is_inside(x_next, y_next, ptr) == 1
					&& (x_next != x || y_next != y))
				{
					if (tab_pixels[x_next][y_next] != 0)
						border_tracing(x_next, y_next, ptr, tab_pixels);
				}
			}
		}
	}
	return (0);
}
