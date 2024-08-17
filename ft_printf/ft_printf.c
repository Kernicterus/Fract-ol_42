/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:15:26 by nledent           #+#    #+#             */
/*   Updated: 2023/11/29 19:03:49 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		chars_printed;
	va_list	params;

	chars_printed = 0;
	if (str == NULL)
		return (-1);
	else if (ft_strlen_printf(str) == 1 && str[0] == '%')
		return (-1);
	else if (ft_strchr_printf(str, '%') == 0)
		ft_putstr_printf(str, &chars_printed);
	else
	{
		va_start(params, str);
		ft_printf_toscreen(params, str, &chars_printed);
		va_end(params);
	}
	return (chars_printed);
}
