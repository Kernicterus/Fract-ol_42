/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 19:59:58 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_iter(t_complex *c_pixel, t_display *ptr)
{
	t_complex	nbstart;
	int			iter;

	iter = 0;
	nbstart.x = c_pixel->x;
	nbstart.y = c_pixel->y;
	while (iter < ptr->details)
	{
		*c_pixel = multipl_complex(*c_pixel, *c_pixel);
		c_pixel->x = c_pixel->x + ptr->c.x;
		c_pixel->y = c_pixel->y + ptr->c.y;
		if (c_pixel->x * c_pixel->x + c_pixel->y * c_pixel->y >= 9)
			return (iter);
		if (c_pixel->x == nbstart.x && c_pixel->y == nbstart.y)
			(iter) = ptr->details - 1;
		(iter)++;
	}
	return (iter);
}

int	ft_julia(t_complex *pixel, t_display *ptr, int **tab_pixels)
{
	int			color;
	int			iter;
	t_complex	c_pixel;

	pos_pixel_complex(&c_pixel, pixel, ptr);
	iter = julia_iter(&c_pixel, ptr);
	color = 0;
	if (iter == ptr->details)
		color = rgb_to_int(0, 0, 0);
	else
		color = rgb_to_int(1 + 10 * iter, iter * 2, iter * 2);
	pixel_to_buffer(color, pixel->x, pixel->y, ptr);
	tab_pixels[(int)pixel->x][(int)pixel->y] = color;
	return (color);
}

void	display_julia(t_display *ptr, int **tab_pixels)
{
	t_complex	pixel;
	int			is_connex;

	pixel.x = 0;
	pixel.y = 0;
	is_connex = julia_iter(&pixel, ptr);
	pixel.y = 0;
	if (is_connex == ptr->details)
		fractol_borders(ptr, tab_pixels);
	else
	{
		while (pixel.y < ptr->win_h)
		{
			pixel.x = 0;
			while (pixel.x < ptr->win_w)
			{
				ft_julia(&pixel, ptr, tab_pixels);
				(pixel.x)++;
			}
			(pixel.y)++;
		}
	}
}
