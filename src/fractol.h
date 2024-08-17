/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:54 by nledent           #+#    #+#             */
/*   Updated: 2024/01/15 20:42:10 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>
# define MLX_ERROR 1
# define COLORS_NB 6
# define COLOR_SETS 4

typedef struct s_complex
{
	long double	x;
	long double	y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_display
{
	int				details;
	int				win_w;
	int				win_h;
	void			*mlx_ptr;
	void			*win_ptr;
	char			fractal;
	long double		zoom;
	int				colors[COLORS_NB + 1];
	t_img			img_data;
	t_complex		c;
}	t_display;

long double	win_x_to_complex_x(double x_screen, t_display *ptr);
long double	win_y_to_complex_y(double y_screen, t_display *ptr);
int			ft_julia(t_complex *pixel, t_display *ptr, int **tab_pixels);
int			ft_mandelbrot(t_complex *pixel, t_display *ptr, int **tab_pixels);
int			is_there_color_around(int x, int y, t_display *ptr, int **tab_pix);
void		zoom(t_display *ptr, int in_or_out);
void		ft_exit(t_display *ptr);
int			ft_print_to_screen(t_display *ptr);
void		check_arg(int argc, char **argv, t_display *ptr);		
void		pos_pixel_complex(t_complex *pixel_im, t_complex *px, t_display *p);
void		fractol_borders(t_display *ptr, int **tab_pixels);
void		pixel_to_buffer(int color, int x, int y, t_display *ptr);
int			press_key(int key, t_display *ptr);
int			mouse_button(int button, int x, int y, t_display *ptr);
int			rgb_to_int(int r, int g, int b);
int			mandelbrot_iter(t_complex *c_pixel, t_display *ptr);
int			border_tracing(int x, int y, t_display *ptr, int **tab_pixels);
void		ft_error(void);
void		display_julia(t_display *ptr, int **tab_pixels);
void		display_mandelbrot(t_display *ptr, int **tab_pixels);
void		fill_rest(t_display *ptr, int **tab_pixels, int color);
t_complex	multipl_complex(t_complex n1, t_complex n2);

#endif