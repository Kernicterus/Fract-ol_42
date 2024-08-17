/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:29:12 by nledent           #+#    #+#             */
/*   Updated: 2023/11/12 18:55:39 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_el;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_el = ft_lstlast(*lst);
			last_el->next = new;
		}
	}
}
