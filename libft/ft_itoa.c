/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:12:00 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 17:07:36 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int nbr)
{
	int	nb;

	nb = nbr;
	if (nb < 0)
		return (1 + len_nb(nb * -1));
	else if (nb / 10 == 0)
		return (1);
	else
		return (1 + len_nb(nb / 10));
}

static void	putnbr_base(int nbr, char *base_to, int *i, char *buf)
{
	int	nb;
	int	len_base;

	nb = nbr;
	len_base = 0;
	while (base_to[len_base] != 0)
		len_base ++;
	if (nb < 0)
	{
		nb = nb * -1;
		buf[*i] = '-';
		*i = *i + 1;
	}
	if (nb / len_base == 0)
	{
		buf[*i] = base_to[nb];
		*i = *i + 1;
	}
	else
	{
		putnbr_base(nb / len_base, base_to, i, buf);
		buf[*i] = base_to[nb % len_base];
		*i = *i + 1;
	}
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		buf = ft_strdup("-2147483648");
		if (buf == NULL)
			return (NULL);
	}
	else
	{
		buf = malloc (sizeof(char) * (len_nb(n) + 1));
		if (buf == NULL)
			return (NULL);
		putnbr_base(n, "0123456789", &i, buf);
		buf[i] = 0;
	}
	return (buf);
}
