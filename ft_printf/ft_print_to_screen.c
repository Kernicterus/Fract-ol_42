/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_to_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:20:33 by nledent           #+#    #+#             */
/*   Updated: 2023/11/29 19:09:53 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pt(unsigned long pt, int *chars_printed)
{
	if (pt)
	{
		write(1, "0x", 2);
		(*chars_printed) += 2;
		ft_putadress_hexa_printf(pt, chars_printed);
	}
	else
	{
		write(1, "(nil)", 5);
		(*chars_printed) += 5;
	}
}

static void	print_var(char type_var, va_list params, int *chars_printed)
{
	if (type_var == 'c')
		ft_putchar_printf(va_arg(params, int), chars_printed);
	else if (type_var == 's')
		ft_putstr_printf(va_arg(params, char *), chars_printed);
	else if (type_var == 'p')
		print_pt(va_arg(params, unsigned long), chars_printed);
	else if (type_var == 'd' || type_var == 'i')
		ft_putnbr_printf(va_arg(params, int), chars_printed);
	else if (type_var == 'u')
		ft_putnbr_u_printf(va_arg(params, int), chars_printed);
	else if (type_var == 'x')
		ft_putnbr_hexa_printf(va_arg(params, unsigned int), chars_printed);
	else if (type_var == 'X')
		ft_putnbr_hexa_maj_printf(va_arg(params, unsigned int), chars_printed);
	else if (type_var == '%')
	{
		(*chars_printed)++;
		write(1, "%", 1);
	}
	else
		(*chars_printed) = -1;
}

static int	print_until_percent(const char *str, int index, int *chars_printed)
{
	while (str[index] != 0 && str[index] != '%')
	{
		write(1, &str[index], 1);
		(*chars_printed)++;
		index++;
	}
	return (index);
}

int	ft_printf_toscreen(va_list params, const char *str, int *chars_printed)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i = print_until_percent(str, i, chars_printed);
		if (str[i] == 0)
			break ;
		else if (ft_strchr_printf("cspdiuxX%", str[i + 1])
			!= 0 && str[i + 1] != 0)
		{
			print_var(str[i + 1], params, chars_printed);
			i += 2;
		}
		else
		{
			ft_putchar_printf(str[i], chars_printed);
			i++;
		}
	}
	return (i);
}
