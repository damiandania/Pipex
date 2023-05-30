/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:29:09 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:00 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Crea una cadena de caracteres aplicando a cada uno de sus caracteres la
// funcion de f la cual no esta definida si no que es una funcion a definir

#include "../includes/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*new_str;

	i = 0;
	if (str && f)
	{
		new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (new_str)
		{
			while (str[i])
			{
				new_str[i] = (*f)(i, str[i]);
				i++;
			}
			new_str[i] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
