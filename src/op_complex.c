/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:20 by nledent           #+#    #+#             */
/*   Updated: 2024/01/12 17:10:10 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	multipl_complex(t_complex n1, t_complex n2)
{
	t_complex	result;

	result.x = 0;
	result.y = 0;
	result.x = (n1.x * n2.x) - (n1.y * n2.y);
	result.y = (n1.x * n2.y) + (n1.y * n2.x);
	return (result);
}
