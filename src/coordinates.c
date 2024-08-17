/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/13 13:40:09 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	win_x_to_complex_x(double x_screen, t_display *ptr)
{
	long double	x;
	double		x_shift;
	double		x_scale;

	if (ptr->win_h > ptr->win_w)
		x_scale = ptr->win_w / 2;
	else
		x_scale = ptr->win_h / 2;
	x_shift = ptr->win_w / 2;
	x = x_screen - x_shift;
	x = x / x_scale;
	x = x * ptr->zoom;
	return (x);
}

long double	win_y_to_complex_y(double y_screen, t_display *ptr)
{
	long double	y;
	double		y_shift;
	double		y_scale;

	if (ptr->win_h > ptr->win_w)
		y_scale = ptr->win_w / 2;
	else
		y_scale = ptr->win_h / 2;
	y_shift = ptr->win_h / 2;
	y = y_shift - y_screen;
	y = y / y_scale;
	y = y * ptr->zoom;
	return (y);
}

void	zoom(t_display *ptr, int in_or_out)
{
	if (in_or_out == 4)
		ptr->zoom = ptr->zoom / 1.1;
	else if (in_or_out == 5)
		ptr->zoom = ptr->zoom * 1.1;
	ft_print_to_screen(ptr);
}

void	pos_pixel_complex(t_complex *pixel_im, t_complex *pixel, t_display *ptr)
{
	pixel_im->x = win_x_to_complex_x(pixel->x, ptr);
	pixel_im->y = win_y_to_complex_y(pixel->y, ptr);
	pixel_im->x = pixel_im->x;
	pixel_im->y = pixel_im->y;
}
