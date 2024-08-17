/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_julia_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 19:54:44 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	minijulia_iter(t_complex *c_pixel, t_display *ptr)
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

static int	ft_minijulia(t_complex *pixel, t_display *ptr)
{
	int			color;
	int			iter;
	t_complex	c_pixel;

	pos_px_cplx_minij(&c_pixel, pixel, ptr);
	iter = minijulia_iter(&c_pixel, ptr);
	color = 0;
	if (iter == ptr->details)
		color = rgb_to_int(0, 0, 0);
	else
	{
		if (ptr->smooth == 1)
			color = smooth_coloring(c_pixel.x, c_pixel.y, iter, ptr);
		else
			color = rgb_to_int(1 + 10 * iter, iter * 2, iter * 2);
	}
	pixel_to_buffer(color, pixel->x + 10, pixel->y + 10, ptr);
	return (color);
}

static void	put_mini_julia(t_display *ptr)
{
	t_complex	pixel;
	int			color;

	if (ptr->color_set % 2 == 0)
		color = rgb_to_int(255, 255, 255);
	else
		color = rgb_to_int(0, 0, 0);
	pixel.y = 0;
	while (pixel.y < ptr->win_h + 12)
	{
		pixel.x = 0;
		while (pixel.x < ptr->win_w + 12)
		{
			if (pixel.x < ptr->win_w && pixel.y < ptr->win_h)
				ft_minijulia(&pixel, ptr);
			if ((pixel.x > 7 && pixel.y < 10 && pixel.y > 7)
				|| (pixel.x > ptr->win_w + 9 && pixel.y > 7))
				pixel_to_buffer(color, pixel.x, pixel.y, ptr);
			else if ((pixel.y > ptr->win_h + 9 && pixel.x > 7)
				|| (pixel.y > 7 && pixel.x < 10 && pixel.x > 7))
				pixel_to_buffer(color, pixel.x, pixel.y, ptr);
			(pixel.x)++;
		}
		(pixel.y)++;
	}
}

void	display_mini_julia(t_display *ptr, t_complex pos_mouse)
{
	int			witdh_tmp;
	int			height_tmp;
	int			color_set_tmp;

	color_set_tmp = ptr->color_set;
	ptr->color_set = (ptr->color_set + 2) % COLOR_SETS;
	init_color_set(ptr);
	pos_pixel_complex(&(ptr->c), &pos_mouse, ptr);
	ptr->c.x = ptr->c.x - 0.6;
	witdh_tmp = ptr->win_w;
	height_tmp = ptr->win_h;
	ptr->win_w = ptr->win_w / 4;
	ptr->win_h = ptr->win_h / 3;
	put_mini_julia(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img_data.img, 0, 0);
	ptr->win_w = witdh_tmp;
	ptr->win_h = height_tmp;
	ptr->color_set = color_set_tmp;
	init_color_set(ptr);
}
