/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/13 14:00:35 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	press_key(int key, t_display *ptr)
{
	if (key == 65307)
		ft_exit(ptr);
	ft_print_to_screen(ptr);
	return (1);
}

int	mouse_button(int button, int x, int y, t_display *ptr)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(ptr, 4);
	else if (button == 5)
		zoom(ptr, 5);
	return (1);
}
