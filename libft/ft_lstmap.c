/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:35:40 by nledent           #+#    #+#             */
/*   Updated: 2023/11/15 13:43:46 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	t_list	*ptlst;
	void	*new_content;

	new_list = 0;
	if (lst)
	{
		ptlst = lst;
		while (ptlst)
		{
			new_content = (*f)(ptlst->content);
			new_element = ft_lstnew(new_content);
			if (new_element == NULL)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_element);
			ptlst = ptlst->next;
		}
		return (new_list);
	}
	else
		return (NULL);
}
