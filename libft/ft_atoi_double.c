/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:08 by nledent           #+#    #+#             */
/*   Updated: 2023/11/30 21:44:09 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	record_nb(long double *nb, const char *str, int *min_one_nb, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = (*nb) * 10 + (str[*i] - 48);
		if (str[*i + 1] != 0)
			*min_one_nb = 1;
		(*i)++;
	}
}

static void	record_decimal(long double *nb, const char *str, int *i, double pow)
{
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = (*nb) + ((str[*i] - 48) / (pow * 10));
		(*i)++;
		record_decimal(nb, str, i, pow * 10);
	}
}

long double	ft_atoi_double(const char *str)
{
	long double	nb;
	int			i;
	int			j;
	int			min_one_nb;

	i = 0;
	j = 1;
	nb = 0;
	min_one_nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	record_nb(&nb, str, &min_one_nb, &i);
	if ((str[i] == '.' || str[i] == ',') && min_one_nb > 0
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	record_decimal(&nb, str, &i, 1);
	return (nb * j);
}
