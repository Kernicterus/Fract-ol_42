/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:26:07 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 16:54:59 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_elements(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i] != NULL)
	{
		free(str_split[i]);
		i++;
	}
	free(str_split);
	return (0);
}

static int	el_to_tab(const char *str, char c, char **str_split, int tot_el)
{
	int	el_start;
	int	i;
	int	nb_el;

	i = 0;
	el_start = 0;
	nb_el = 0;
	while (str[i] != 0 && (nb_el < tot_el))
	{
		while (str[i] == c && str[i] != 0)
			i++;
		if (str[i] != c && str[i] != 0)
		{
			nb_el++;
			el_start = i;
		}
		while (str[i] != c && str[i] != 0)
			i++;
		str_split[nb_el - 1] = malloc(sizeof(char) * (i - el_start + 1));
		if (str_split[nb_el - 1] == NULL)
			return (free_elements(str_split));
		ft_strlcpy(str_split[nb_el - 1], &str[el_start], i - el_start + 1);
	}
	return (1);
}

static int	count_nb_element(char const *str, char c)
{
	int	nb_elements;
	int	i;

	i = 0;
	nb_elements = 0;
	if (str[0] == 0)
		return (0);
	while (str[i] != 0)
	{
		while (str[i] == c && str[i] != 0)
			i++;
		if (str[i] != c && str[i] != 0)
			nb_elements++;
		while (str[i] != c && str[i] != 0)
			i++;
	}
	return (nb_elements);
}

char	**ft_split(char const *s, char c)
{
	char		**str_split;
	int			nb_element;

	str_split = 0;
	nb_element = 0;
	if (s == 0)
		return (0);
	nb_element = count_nb_element(s, c);
	str_split = malloc(sizeof(char *) * (nb_element + 1));
	if (str_split == NULL)
		return (0);
	str_split[nb_element] = 0;
	if (nb_element == 0)
	{
		str_split[0] = 0;
		return (str_split);
	}
	else if (el_to_tab(s, c, str_split, nb_element) == 1)
		return (str_split);
	else
		return (0);
}
