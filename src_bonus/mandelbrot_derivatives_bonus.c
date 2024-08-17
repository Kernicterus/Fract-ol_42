/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_derivatives_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/18 13:07:46 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	loop_mandelbrot_d_iter(t_display *ptr, t_complex *pixel_im)
{
	long double		x_tmp;
	int				iter;
	int				pow;

	pow = ptr->power;
	iter = 0;
	while (iter < ptr->details)
	{
		x_tmp = powl((ptr->c.x * ptr->c.x + ptr->c.y * ptr->c.y), pow / 2)
			* cos(pow * atan2(ptr->c.y, ptr->c.x));
		ptr->c.y = powl((ptr->c.x * ptr->c.x + ptr->c.y * ptr->c.y), pow / 2)
			* sin(pow * atan2(ptr->c.y, ptr->c.x)) + pixel_im->y;
		ptr->c.x = x_tmp + pixel_im->x;
		if (ptr->c.x * ptr->c.x + ptr->c.y * ptr->c.y >= 4)
			return (iter);
		if (ptr->c.x == 0 && ptr->c.y == 0)
			(iter) = ptr->details - 1;
		(iter)++;
	}
	return (iter);
}

static int	mandelbrot_d_iter(t_complex *pixel, t_display *ptr)
{
	t_complex		pixel_im;
	int				iter;

	iter = 0;
	pos_pixel_complex(&pixel_im, pixel, ptr);
	if (ptr->power < 0)
	{
		ptr->c.x = pixel_im.x;
		ptr->c.y = pixel_im.y;
	}
	else
	{
		ptr->c.x = 0;
		ptr->c.y = 0;
	}
	if (ptr->inverted == 1)
		pixel_im = invert_complex(pixel_im);
	iter = loop_mandelbrot_d_iter(ptr, &pixel_im);
	return (iter);
}

int	ft_mandelbrot_d(t_complex *pixel, t_display *ptr, int **tab_pixels)
{
	int	color;
	int	iter;

	iter = mandelbrot_d_iter(pixel, ptr);
	color = 0;
	if (iter == ptr->details)
		color = rgb_to_int(0, 0, 0);
	else
	{
		if (ptr->smooth == 1)
			color = smooth_coloring(ptr->c.x, ptr->c.y, iter, ptr);
		else
			color = rgb_to_int(1 + 10 * iter, iter * 2, iter * 2);
	}
	pixel_to_buffer(color, pixel->x, pixel->y, ptr);
	tab_pixels[(int)pixel->x][(int)pixel->y] = color;
	return (color);
}

void	fractol_borders_d(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;
	int			finish;

	reach_borders_x(tab_pixels, ptr, ptr->win_w / 2, ptr->win_h / 2);
	reach_borders_y(tab_pixels, ptr, ptr->win_w / 2, ptr->win_h / 2);
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

void	display_mandelbrot_d(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;

	if (ptr->power > 0 && ptr->inverted == 0)
		fractol_borders(ptr, tab_pixels);
	else if (ptr->power > 0 && ptr->inverted == 1)
		fractol_borders_d(ptr, tab_pixels);
	else
	{
		pixel.y = 0;
		while (pixel.y < ptr->win_h)
		{
			pixel.x = 0;
			while (pixel.x < ptr->win_w)
			{
				ft_mandelbrot_d(&pixel, ptr, tab_pixels);
				(pixel.x)++;
			}
			(pixel.y)++;
		}
	}
}
