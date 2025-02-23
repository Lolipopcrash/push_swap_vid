/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:07:20 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/28 17:32:50 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_entry;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_entry = NULL;
	while (lst)
	{
		new_content = ft_lstnew(f(lst->content));
		if (!new_content)
		{
			ft_lstclear(&new_entry, del);
			return (NULL);
		}
		ft_lstadd_back(&new_entry, new_content);
		lst = lst->next;
	}
	return (new_entry);
}
