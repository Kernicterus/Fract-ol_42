/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:07:39 by nledent           #+#    #+#             */
/*   Updated: 2023/11/13 19:16:41 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_from_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	len_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (is_from_set(s1[i], set) == 1)
		i++;
	while (s1[i] != 0)
	{
		len++;
		i++;
	}
	i--;
	if (len > 0)
	{
		while (is_from_set(s1[i], set) == 1)
		{
			i--;
			len--;
		}
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*pt;

	i = 0;
	j = 0;
	pt = NULL;
	if (!s1)
		return (pt);
	len = len_strtrim(s1, set);
	pt = malloc(sizeof(char) * (len + 1));
	if (pt == NULL)
		return (NULL);
	while (is_from_set(s1[i], set) == 1)
		i++;
	while (j < len)
	{
		pt[j] = s1[i];
		i++;
		j++;
	}
	pt[j] = 0;
	return (pt);
}
