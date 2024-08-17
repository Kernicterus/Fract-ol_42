/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:26:09 by nledent           #+#    #+#             */
/*   Updated: 2023/11/06 22:15:39 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_printf(const char *s, int *chars_printed)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != 0)
		{
			write(1, &s[i], 1);
			(*chars_printed)++;
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		(*chars_printed) += 6;
	}
}
