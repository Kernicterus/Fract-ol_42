/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 16:21:46 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	t_complex	mouse_post_zoom;

	ptr->c_mouse.x = win_x_to_complex_x(ptr->mouse.x, ptr) - ptr->offset_x;
	ptr->c_mouse.y = win_y_to_complex_y(ptr->mouse.y, ptr) - ptr->offset_y;
	if (in_or_out == 4)
		ptr->zoom = ptr->zoom / 1.1;
	else if (in_or_out == 5)
		ptr->zoom = ptr->zoom * 1.1;
	mouse_post_zoom.x = win_x_to_complex_x(ptr->mouse.x, ptr);
	mouse_post_zoom.y = win_y_to_complex_y(ptr->mouse.y, ptr);
	ptr->offset_x = (mouse_post_zoom.x - ptr->c_mouse.x);
	ptr->offset_y = (mouse_post_zoom.y - ptr->c_mouse.y);
	ft_print_to_screen(ptr);
}

void	pos_pixel_complex(t_complex *pixel_im, t_complex *pixel, t_display *ptr)
{
	pixel_im->x = win_x_to_complex_x(pixel->x, ptr);
	pixel_im->y = win_y_to_complex_y(pixel->y, ptr);
	pixel_im->x = pixel_im->x - ptr->offset_x;
	pixel_im->y = pixel_im->y - ptr->offset_y;
	if (ptr->fractal == 'B')
		pixel_im->y *= -1;
}
