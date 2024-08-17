/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:40 by nledent           #+#    #+#             */
/*   Updated: 2023/11/12 18:52:41 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptlst;

	if (lst)
	{
		ptlst = lst;
		while (ptlst->next)
		{
			ptlst = ptlst->next;
		}
		return (ptlst);
	}
	else
		return (NULL);
}
