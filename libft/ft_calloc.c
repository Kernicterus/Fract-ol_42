/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:55:14 by nledent           #+#    #+#             */
/*   Updated: 2023/11/13 15:53:10 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t el_count, size_t el_size)
{
	size_t			i;
	size_t			check;
	unsigned char	*pt;

	i = 0;
	pt = 0;
	check = el_count * el_size;
	if (el_count == 0)
	{
		pt = malloc(0);
		return (pt);
	}
	if (check / el_count != el_size)
		return (NULL);
	pt = malloc(el_size * el_count);
	if (pt == NULL)
		return (pt);
	while (i < el_size * el_count)
	{
		pt[i] = 0;
		i++;
	}
	return (pt);
}
