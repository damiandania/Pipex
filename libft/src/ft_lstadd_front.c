/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:54:02 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:42:01 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Agrega un nodo en la parte superio de una lista

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
