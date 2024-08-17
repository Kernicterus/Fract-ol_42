/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:24:45 by nledent           #+#    #+#             */
/*   Updated: 2023/11/11 17:59:18 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_u_printf(unsigned int nb, int *chars_printed)
{
	if (nb / 10 == 0)
	{
		nb = nb % 10 + '0';
		write(1, &nb, 1);
		(*chars_printed)++;
	}
	else
	{
		ft_putnbr_u_printf(nb / 10, chars_printed);
		nb = nb % 10 + '0';
		write(1, &nb, 1);
		(*chars_printed)++;
	}
}
