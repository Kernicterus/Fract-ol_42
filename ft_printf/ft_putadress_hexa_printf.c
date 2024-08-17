/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_hexa_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:16:43 by nledent           #+#    #+#             */
/*   Updated: 2023/11/29 17:39:05 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putadress_hexa_printf(unsigned long nb, int *chars_printed)
{
	if (nb / 16 == 0)
	{
		nb = nb % 16;
		if (nb > 9)
			nb = nb + 'a' - 10;
		else
			nb = nb + '0';
		write(1, &nb, 1);
		(*chars_printed)++;
	}
	else
	{
		ft_putadress_hexa_printf(nb / 16, chars_printed);
		nb = nb % 16;
		if (nb > 9)
			nb = nb + 'a' - 10;
		else
			nb = nb + '0';
		write(1, &nb, 1);
		(*chars_printed)++;
	}
}
