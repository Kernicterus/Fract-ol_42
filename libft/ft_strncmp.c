/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:36:55 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:49:07 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
			else if ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] == 0)
			{
				return (0);
			}
			i++;
		}
	}
	return (0);
}
