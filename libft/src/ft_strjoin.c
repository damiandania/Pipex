/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:38 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:03 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	crea un nuevo char con el espacio de str1 + str2, si la memoria falla
	da NULL*/

#include "../includes/libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	char	*newstr;

	if (str1 && str2)
	{
		newstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
		if (newstr)
		{
			i = 0;
			while (*str1)
			{
				newstr[i++] = *str1;
				str1++;
			}
			while (*str2)
			{
				newstr[i++] = *str2;
				str2++;
			}
			newstr[i] = '\0';
			return (newstr);
		}
	}
	return (NULL);
}
