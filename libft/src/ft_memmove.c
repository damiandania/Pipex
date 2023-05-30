/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:54:59 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Copia n cantidad de bytes de src en dest, pero moviendo
	primeramente los parametros a buffer para evitar la perdida
	de datos*/

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (pdest > psrc)
	{
		while (0 < n--)
			pdest[n] = psrc[n];
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
