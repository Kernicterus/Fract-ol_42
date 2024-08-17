/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 19:56:40 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	rgb_to_int(int r, int g, int b)
{
	int	color_int;

	color_int = (r << 16 | g << 8 | b);
	return (color_int);
}

static double	nu_calculator(double x, double y, int iter)
{
	double	nu;
	double	log_zn;
	double	iter_db;

	log_zn = log(x * x + y * y) / 2;
	nu = log(log_zn / log(2)) / log(2);
	iter_db = iter + 1 - nu;
	return (iter_db);
}

int	linear_interpolation(int color1, int color2, double percent)
{
	double	red;
	double	green;
	double	blue;
	int		color_result;

	red = (1 - percent) * ((color1 >> 16) & 255)
		+ (percent) * ((color2 >> 16) & 255);
	color_result = ((int)(red / 1) << 16);
	green = (1 - percent) * ((color1 >> 8) & 255)
		+ (percent) * ((color2 >> 8) & 255);
	color_result += ((int)(green / 1) << 8);
	blue = (1 - percent) * (color1 & 255)
		+ (percent) * (color2 & 255);
	color_result += (int)(blue / 1);
	return (color_result);
}

int	smooth_coloring(double x, double y, int iter, t_display *ptr)
{
	int		color1_index;
	int		color1;
	int		color2;
	int		color_result;
	double	iter_db;

	iter_db = nu_calculator(x, y, iter);
	if (iter_db < 0)
		return (ptr->colors[0]);
	color1_index = (int)(iter_db / 10) % COLORS_NB;
	color1 = ptr->colors[color1_index];
	color2 = ptr->colors[color1_index + 1];
	color_result = linear_interpolation(color1, color2, (iter_db / 10)
			- (int)(iter_db / 10));
	return (color_result);
}
