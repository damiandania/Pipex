/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:51:59 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:58 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	retorna el puntero de la ultima ocurrencia de c en str,
 *	si no lo consigue retorna NULL*/

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*pstr;

	pstr = NULL;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			pstr = (char *)str;
		str++;
	}
	if (!c)
		return ((char *)str);
	return ((char *)pstr);
}
