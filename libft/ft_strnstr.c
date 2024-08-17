/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:05:28 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:49:11 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!str || !substr) && len == 0)
		return (NULL);
	if (substr[0] == 0)
		return ((char *)str);
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] != 0 && str[i + j] == substr[j] && (i + j) < len)
			j++;
		if (substr[j] == 0)
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}
