/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:02:29 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Busca la primera coincidencia de c en str y retorna el
	puntero de dicha posicion */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*pstr;
	unsigned char	c2;

	i = 0;
	pstr = (unsigned char *)str;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (*pstr == c2)
			return (pstr);
		pstr++;
		i++;
	}
	return (NULL);
}
