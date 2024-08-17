/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:07:20 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 10:55:17 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest || src)
	{
		if (dest < src)
		{
			i = 0;
			while (i < n)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
		else
		{
			i = 1;
			while (i <= n)
			{
				((unsigned char *)dest)[n - i] = ((unsigned char *)src)[n - i];
				i++;
			}
		}
	}
	return (dest);
}
