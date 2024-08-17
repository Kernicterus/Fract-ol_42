/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:52:27 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:48:46 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_str(char const *s1, char const *s2, char *strcat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		strcat[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		strcat[i] = s2[j];
		i++;
		j++;
	}
	strcat[i] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;

	strcat = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return ((char *)s2);
	else if (s2 == NULL)
		return ((char *)s1);
	else
	{
		strcat = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (strcat == NULL)
			return (0);
		join_str(s1, s2, strcat);
		return (strcat);
	}
}
