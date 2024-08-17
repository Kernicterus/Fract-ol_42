/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 19:59:22 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_to_int(int r, int g, int b)
{
	int	color_int;

	color_int = (r << 16 | g << 8 | b);
	return (color_int);
}

void	fill_rest(t_display *ptr, int **tab_pixels, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < ptr->win_h)
	{
		x = 0;
		while (x < ptr->win_w)
		{
			if (tab_pixels[x][y] == -1)
			{
				tab_pixels[x][y] = color;
				pixel_to_buffer(tab_pixels[x][y], x, y, ptr);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img_data.img, 0, 0);
}
