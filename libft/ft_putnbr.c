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

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb / 10 == 0)
	{
		nb = nb % 10 + '0';
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		nb = nb % 10 + '0';
		write(1, &nb, 1);
	}
}
