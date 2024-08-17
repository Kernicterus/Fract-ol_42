/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:54 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 19:49:56 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ptr->zoom = 2;
	ptr->fractal = argv[1][0];
	ptr->win_w = 500;
	ptr->win_h = 500;
	ptr->details = 50;
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
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
