/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:21:01 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:42:59 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actual_el;

	if (lst && f)
	{
		actual_el = lst;
		while (actual_el != NULL)
		{
			(*f)(actual_el->content);
			actual_el = actual_el->next;
		}
	}
}
