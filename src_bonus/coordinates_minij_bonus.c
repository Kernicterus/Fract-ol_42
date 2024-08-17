/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_minij_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 16:21:56 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static long double	win_x_to_complex_minij(double x_screen, t_display *ptr)
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
	x = x * 2;
	return (x);
}

static long double	win_y_to_complex_minij(double y_screen, t_display *ptr)
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
	y = y * 2;
	return (y);
}

void	pos_px_cplx_minij(t_complex *pixel_im, t_complex *pixel, t_display *ptr)
{
	pixel_im->x = win_x_to_complex_minij(pixel->x, ptr);
	pixel_im->y = win_y_to_complex_minij(pixel->y, ptr);
}
