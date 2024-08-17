/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:15:03 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:49:28 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_extr;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	else if (ft_strlen(s) <= start)
		len = 0;
	else if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	s_extr = malloc (sizeof (char) * (len + 1));
	if (s_extr == NULL)
		return (NULL);
	ft_memset(s_extr, 0, (len + 1));
	if (len == 0)
		return (s_extr);
	while (s[start + i] != 0 && i < len)
	{
		s_extr[i] = s[start + i];
		i++;
	}
	return (s_extr);
}
