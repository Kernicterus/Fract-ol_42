/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 19:53:27 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	init_color_set1(t_display *ptr)
{
	if (ptr->color_set == 0)
	{
		ptr->colors[0] = rgb_to_int(0, 0, 100);
		ptr->colors[1] = rgb_to_int(100, 0, 100);
		ptr->colors[2] = rgb_to_int(150, 50, 80);
		ptr->colors[3] = rgb_to_int(240, 200, 0);
		ptr->colors[4] = rgb_to_int(150, 50, 80);
		ptr->colors[5] = rgb_to_int(100, 0, 100);
		ptr->colors[6] = rgb_to_int(0, 0, 100);
	}
	else if (ptr->color_set == 1)
	{
		ptr->colors[0] = rgb_to_int(50, 0, 50);
		ptr->colors[1] = rgb_to_int(0, 0, 255);
		ptr->colors[2] = rgb_to_int(255, 255, 80);
		ptr->colors[3] = rgb_to_int(255, 100, 0);
		ptr->colors[4] = rgb_to_int(250, 60, 150);
		ptr->colors[5] = rgb_to_int(100, 0, 150);
		ptr->colors[6] = rgb_to_int(50, 0, 50);
	}
}

static void	init_color_set2(t_display *ptr)
{
	if (ptr->color_set == 2)
	{
		ptr->colors[0] = rgb_to_int(20, 0, 0);
		ptr->colors[1] = rgb_to_int(150, 0, 0);
		ptr->colors[2] = rgb_to_int(255, 100, 20);
		ptr->colors[3] = rgb_to_int(255, 255, 0);
		ptr->colors[4] = rgb_to_int(150, 0, 0);
		ptr->colors[5] = rgb_to_int(255, 100, 20);
		ptr->colors[6] = rgb_to_int(20, 0, 0);
	}
	else if (ptr->color_set == 3)
	{
		ptr->colors[0] = rgb_to_int(120, 250, 250);
		ptr->colors[1] = rgb_to_int(50, 240, 75);
		ptr->colors[2] = rgb_to_int(223, 115, 255);
		ptr->colors[3] = rgb_to_int(0, 0, 255);
		ptr->colors[4] = rgb_to_int(255, 50, 80);
		ptr->colors[5] = rgb_to_int(100, 0, 100);
		ptr->colors[6] = rgb_to_int(120, 250, 250);
	}
}

void	init_color_set(t_display *ptr)
{
	init_color_set1(ptr);
	init_color_set2(ptr);
}

void	fill_rest(t_display *ptr, int **tab_pixels, int color)
{
	int			x;
	int			y;
	t_complex	pixel;

	y = 0;
	while (y < ptr->win_h)
	{
		x = 0;
		while (x < ptr->win_w)
		{
			if (tab_pixels[x][y] == -1)
			{
				pixel.x = x;
				pixel.y = y;
				tab_pixels[x][y] = color;
				if (!(ptr->fractal == 'M' && ptr->mini_julia == 1
						&& is_in_minij(&pixel, ptr) == 1))
					pixel_to_buffer(tab_pixels[x][y], x, y, ptr);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img_data.img, 0, 0);
}
