/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:34 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:02 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Copia n cantidad de caracteres de src en dst*/

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		dsrc;

	dsrc = ft_strlen(src);
	if (src == 0)
		return (dsrc);
	i = 0;
	if (size)
	{
		while ((src[i] && i < (size - 1)) && size != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dsrc);
}
