/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:08:45 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:05 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Se utiliza para duplicar el contenido de una cadena en otra, crea le memoria
	suficiente para la copia mas el '\0'*/

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ret)
	{
		while (i < ft_strlen(str))
		{
			ret[i] = str[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
