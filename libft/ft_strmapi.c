/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:34:26 by nledent           #+#    #+#             */
/*   Updated: 2023/11/06 22:16:58 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len_str;
	char			*s_cpy;

	i = 0;
	s_cpy = NULL;
	if (!s || !f)
		return (NULL);
	len_str = ft_strlen(s);
	s_cpy = malloc(sizeof (char) * (len_str + 1));
	if (s_cpy == NULL)
		return (NULL);
	while (i < len_str)
	{
		s_cpy[i] = (*f)(i, s[i]);
		i++;
	}
	s_cpy[len_str] = 0;
	return (s_cpy);
}
