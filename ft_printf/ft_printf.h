/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:30:36 by nledent           #+#    #+#             */
/*   Updated: 2023/11/29 19:03:40 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putstr_printf(const char *s, int *chars_printed);
void	ft_putchar_printf(const char c, int *chars_printed);
void	ft_putnbr_printf(int n, int *chars_printed);
void	ft_putnbr_u_printf(unsigned int nb, int *chars_printed);
void	ft_putnbr_hexa_printf(unsigned int nb, int *chars_printed);
void	ft_putnbr_hexa_maj_printf(unsigned int nb, int *chars_printed);
void	ft_putadress_hexa_printf(unsigned long nb, int *chars_printed);
char	*ft_strchr_printf(const char *s, int c);
int		ft_printf_toscreen(va_list params, const char *str, int *chars_printed);
int		ft_printf(const char *str, ...);
size_t	ft_strlen_printf(const char *str);

#endif
