/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:01:28 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 10:36:47 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		x;
	int		i;

	i = 0;
	x = ft_strlen(s) + 1;
	str = malloc(x * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
