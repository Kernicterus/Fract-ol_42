/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:08 by nledent           #+#    #+#             */
/*   Updated: 2023/11/06 22:14:50 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*actual_el;
	int		size;

	size = 0;
	if (lst)
	{
		actual_el = lst;
		while (actual_el != NULL)
		{
			actual_el = actual_el->next;
			size++;
		}
	}
	return (size);
}
