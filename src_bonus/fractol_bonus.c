/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:54 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 20:14:10 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_zoom_offset(t_display *ptr)
{
	if (ptr->fractal == 'D')
	{
		ptr->win_w = 350;
		ptr->win_h = 350;
	}
	else
	{
		ptr->win_w = 1000;
		ptr->win_h = 750;
	}
	ptr->zoom = 2;
	ptr->mouse.x = ptr->win_w / 2;
	ptr->mouse.y = ptr->win_h / 2;
	ptr->offset_x = 0;
	ptr->offset_y = 0;
	ptr->c_mouse.x = win_x_to_complex_x(ptr->mouse.x, ptr);
	ptr->c_mouse.y = win_y_to_complex_y(ptr->mouse.y, ptr);
}

static void	init_win(t_display *ptr)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit(MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, ptr->win_w, ptr->win_h, "fractol");
	ptr->img_data.img = mlx_new_image(mlx_ptr, ptr->win_w, ptr->win_h);
	if (win_ptr == NULL || ptr->img_data.img == NULL)
	{
		if (win_ptr != NULL)
			free(win_ptr);
		if (ptr->img_data.img != NULL)
			free(ptr->img_data.img);
		free(mlx_ptr);
		exit(MLX_ERROR);
	}
	ptr->img_data.addr = mlx_get_data_addr(ptr->img_data.img,
			&(ptr->img_data.bits_per_pixel), &(ptr->img_data.line_length),
			&(ptr->img_data.endian));
	ptr->mlx_ptr = mlx_ptr;
	ptr->win_ptr = win_ptr;
}

static void	init_ptr(t_display *ptr, char **argv)
{
	ptr->fractal = argv[1][0];
	init_zoom_offset(ptr);
	ptr->smooth = 0;
	ptr->details = 50;
	ptr->color_set = 0;
	ptr->mini_julia = 0;
}

int	main(int argc, char **argv)
{
	t_display	ptr;

	check_arg(argc, argv, &ptr);
	init_ptr(&ptr, argv);
	init_win(&ptr);
	ft_print_to_screen(&ptr);
	mlx_hook(ptr.win_ptr, 17, 0, (void *)ft_exit, &ptr);
	mlx_key_hook(ptr.win_ptr, press_key, &ptr);
	mlx_mouse_hook(ptr.win_ptr, mouse_button, &ptr);
	mlx_loop_hook(ptr.mlx_ptr, mouse_position, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
