/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/18 13:07:25 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	burning_sh_iter(t_complex *pixel, t_display *ptr)
{
	t_complex		nbstart;
	t_complex		pixel_im;
	long double		x_tmp;
	int				iter;

	iter = 0;
	pos_pixel_complex(&pixel_im, pixel, ptr);
	nbstart.x = 0;
	nbstart.y = 0;
	ptr->c.x = nbstart.x;
	ptr->c.y = nbstart.y;
	while (iter < ptr->details)
	{
		x_tmp = ptr->c.x * ptr->c.x - ptr->c.y * ptr->c.y;
		ptr->c.y = 2 * fabsl(ptr->c.x * ptr->c.y) + pixel_im.y;
		ptr->c.x = x_tmp + pixel_im.x;
		if (ptr->c.x * ptr->c.x + ptr->c.y * ptr->c.y >= 9)
			return (iter);
		if (ptr->c.x == nbstart.x && ptr->c.y == nbstart.y)
			(iter) = ptr->details - 1;
		(iter)++;
	}
	return (iter);
}

static int	ft_burning_sh(t_complex *pixel, t_display *ptr, int **tab_pixels)
{
	int	color;
	int	iter;

	iter = burning_sh_iter(pixel, ptr);
	color = 0;
	if (iter == ptr->details)
		color = rgb_to_int(0, 0, 0);
	else if (iter > 50)
		color = ptr->colors[3];
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

void	display_burning_ship(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;

	pixel.y = 0;
	while (pixel.y < ptr->win_h)
	{
		pixel.x = 0;
		while (pixel.x < ptr->win_w)
		{
			ft_burning_sh(&pixel, ptr, tab_pixels);
			(pixel.x)++;
		}
		(pixel.y)++;
	}
}
