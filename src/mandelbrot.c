/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 20:00:10 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(t_complex *c_pixel, t_display *ptr)
{
	t_complex	nbstart;
	int			iter;

	iter = 0;
	nbstart.x = 0;
	nbstart.y = 0;
	ptr->c.x = nbstart.x;
	ptr->c.y = nbstart.y;
	while (iter < ptr->details)
	{
		ptr->c = multipl_complex(ptr->c, ptr->c);
		ptr->c.x = ptr->c.x + c_pixel->x - 0.6;
		ptr->c.y = ptr->c.y + c_pixel->y;
		if (ptr->c.x * ptr->c.x + ptr->c.y * ptr->c.y >= 9)
			return (iter);
		if (ptr->c.x == nbstart.x && ptr->c.y == nbstart.y)
			(iter) = ptr->details - 1;
		(iter)++;
	}
	return (iter);
}

int	ft_mandelbrot(t_complex *pixel, t_display *ptr, int **tab_pixels)
{
	int			color;
	int			iter;
	t_complex	c_pixel;

	pos_pixel_complex(&c_pixel, pixel, ptr);
	iter = mandelbrot_iter(&c_pixel, ptr);
	color = 0;
	if (iter == ptr->details)
		color = rgb_to_int(0, 0, 0);
	else
		color = rgb_to_int(1 + 10 * iter, iter * 2, iter * 2);
	pixel_to_buffer(color, pixel->x, pixel->y, ptr);
	tab_pixels[(int)pixel->x][(int)pixel->y] = color;
	return (color);
}

void	display_mandelbrot(t_display *ptr, int **tab_pixels)
{
	fractol_borders(ptr, tab_pixels);
}
