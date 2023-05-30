/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:47:21 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:06 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	restorna el puntero de la primera coincidencia de c
 *	en str, si no lo consigue retorna NULL*/

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return (str);
		str++;
	}
	if (c == '\0' && *str == '\0')
		return (str);
	return (NULL);
}
