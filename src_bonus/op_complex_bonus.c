/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_complex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/16 19:58:00 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	multipl_complex(t_complex n1, t_complex n2)
{
	t_complex	result;

	result.x = 0;
	result.y = 0;
	result.x = (n1.x * n2.x) - (n1.y * n2.y);
	result.y = (n1.x * n2.y) + (n1.y * n2.x);
	return (result);
}

t_complex	invert_complex(t_complex c)
{
	t_complex	r;

	r.x = c.x / ((c.x * c.x) + (c.y * c.y));
	r.y = -c.y / ((c.x * c.x) + (c.y * c.y));
	return (r);
}
