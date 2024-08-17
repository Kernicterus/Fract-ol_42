/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:43:42 by nledent           #+#    #+#             */
/*   Updated: 2023/11/13 13:39:06 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*el_to_erase;

	if (lst && del)
	{
		while (*(lst) != NULL)
		{
			el_to_erase = *lst;
			*lst = el_to_erase->next;
			ft_lstdelone(el_to_erase, del);
		}
		lst = NULL;
	}
}
