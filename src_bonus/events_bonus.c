/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/18 13:06:31 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	next_power(t_display *ptr, int key)
{
	if (key == 'z')
	{
		if (ptr->power == 1)
			(ptr->power) = -2;
		else
			(ptr->power)--;
	}
	else if (key == 'e')
	{
		if (ptr->power == -2)
			(ptr->power) = 1;
		else
			(ptr->power)++;
	}
	if (ptr->power > 50)
		ptr->power = -15;
	else if (ptr->power < -15)
		ptr->power = 50;
}

static void	upd_var(int *var)
{
	if (*var == 1)
		*var = 0;
	else
		*var = 1;
}

int	press_key(int key, t_display *ptr)
{
	if (key == 65307)
		ft_exit(ptr);
	else if (key == 32)
		upd_var(&(ptr->smooth));
	else if (key == 'j')
		upd_var(&(ptr->mini_julia));
	else if (key == 65451)
		ptr->details *= 2;
	else if (key == 'c')
		ptr->color_set = (ptr->color_set + 1) % COLOR_SETS;
	else if (ptr->fractal == 'D' && (key == 'z' || key == 'e'))
		next_power(ptr, key);
	else if (key == 65453)
		ptr->details /= 2;
	else if (key == 65362)
		ptr->offset_y = ptr->offset_y - (0.1 * ptr->zoom);
	else if (key == 65364)
		ptr->offset_y = ptr->offset_y + (0.1 * ptr->zoom);
	else if (key == 65363)
		ptr->offset_x = ptr->offset_x - (0.1 * ptr->zoom);
	else if (key == 65361)
		ptr->offset_x = ptr->offset_x + (0.1 * ptr->zoom);
	ft_print_to_screen(ptr);
	return (1);
}

int	mouse_button(int button, int x, int y, t_display *ptr)
{
	t_complex	pixel;

	pixel.x = x;
	pixel.y = y;
	ptr->mouse.x = x;
	ptr->mouse.y = y;
	if (button == 4)
		zoom(ptr, 4);
	else if (button == 5)
		zoom(ptr, 5);
	else if (button == 3)
	{
		if (ptr->fractal == 'J')
			ptr->fractal = 'M';
		else if (ptr->fractal == 'M')
		{
			pos_pixel_complex(&(ptr->c), &pixel, ptr);
			ptr->c.x -= 0.6;
			init_zoom_offset(ptr);
			ptr->fractal = 'J';
		}
		ft_print_to_screen(ptr);
	}
	return (1);
}

int	mouse_position(t_display *ptr)
{
	int			x;
	int			y;
	t_complex	pix_pos_mouse;

	mlx_mouse_get_pos(ptr->mlx_ptr, ptr->win_ptr, &x, &y);
	pix_pos_mouse.x = x;
	pix_pos_mouse.y = y;
	if (ptr->fractal == 'M' && ptr->mini_julia == 1)
		display_mini_julia(ptr, pix_pos_mouse);
	return (1);
}
