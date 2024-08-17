/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 18:50:30 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_tab_pixels(int	**tab_pixels, t_display *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->win_w)
	{
		free(tab_pixels[i]);
		i++;
	}
	free(tab_pixels);
}

void	ft_error(void)
{
	ft_printf("At least one parameter is required to choose a fractal type.\n");
	ft_printf("For Julia set, press \"J\"\n");
	ft_printf("For Mandelbrot set, press \"M\"\n");
	ft_printf("\nNB : For Julia set, you can add up to two double numbers ");
	ft_printf("as parameters to create more fancy things.");
	ft_printf("\nFor example try ./fractol J -0.51 -0.56\n");
	ft_printf("By default, or if an invalid parameter is given, ");
	ft_printf("parameteres will be set at 0 & 0.\n");
	ft_printf("\nNB2 : For other sets, you must not add more parameters.\n");
	exit(-1);
}

void	pixel_to_buffer(int color, int x, int y, t_display *ptr)
{
	char	*dst;

	dst = ptr->img_data.addr + (y * ptr->img_data.line_length
			+ x * (ptr->img_data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	**init_tab_pixels(t_display *ptr)
{
	int	x;
	int	y;
	int	**tab_pixels;

	x = -1;
	tab_pixels = malloc(sizeof(int *) * ptr->win_w);
	if (tab_pixels == NULL)
		return (NULL);
	while (++x < ptr->win_w)
	{
		tab_pixels[x] = malloc(sizeof(int) * ptr->win_h);
		if (tab_pixels[x] == NULL)
		{
			ptr->win_w = x;
			free_tab_pixels(tab_pixels, ptr);
			ft_exit(ptr);
		}
		y = -1;
		while (++y < ptr->win_h)
			tab_pixels[x][y] = -1;
	}
	return (tab_pixels);
}

int	ft_print_to_screen(t_display *ptr)
{
	int			**tab_pixels;

	tab_pixels = init_tab_pixels(ptr);
	if (tab_pixels == 0)
		ft_exit(ptr);
	else if (ptr->fractal == 'J')
		display_julia(ptr, tab_pixels);
	else if (ptr->fractal == 'M')
		display_mandelbrot(ptr, tab_pixels);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img_data.img, 0, 0);
	free_tab_pixels(tab_pixels, ptr);
	return (1);
}
