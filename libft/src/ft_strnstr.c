/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:40 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:59 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	retorna el puntero de la primera coincidencia de lte en big,
 *	si lte es nada se rotorna big y si lte no esta en big se
 *	retorna NULL*/

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *lte, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lte_len;
	char	*pbig;

	i = 0;
	j = 0;
	if ((!big || !lte) && !len)
		return (NULL);
	j = ft_strlen(lte);
	lte_len = j;
	pbig = (char *)big;
	if (lte_len == 0 || big == lte)
		return (pbig);
	while (pbig[i] != '\0' && i < len)
	{
		j = 0;
		while (pbig[i + j] == lte[j] && pbig[i + j] != '\0'
			&& lte[j] != '\0' && (i + j) < len)
			j++;
		if (lte_len == j)
			return (pbig + i);
		i++;
	}
	return (0);
}
