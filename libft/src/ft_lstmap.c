/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:44:50 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Crea una lista nueva con todos sus nodos aplicandole la funcion f

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		aux = ft_lstnew((f)(lst->content));
		if (!aux)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, aux);
		lst = lst->next;
	}
	return (new);
}
