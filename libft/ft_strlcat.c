/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:02:22 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 11:15:05 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	if (size < len_dst + 1)
		return (ft_strlen(src) + size);
	while (dst[i] != 0)
		i++;
	j = i;
	while (i < size - 1 && src[i - j] != 0)
	{
		dst[i] = src[i - j];
		i++;
	}
	dst[i] = 0;
	return (len_dst + ft_strlen(src));
}
