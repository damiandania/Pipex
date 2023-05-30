/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:30 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:04 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ejecuta la funcion f en cada caracter de str

#include "../includes/libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (str && f)
	{
		while (str[i])
		{
			(*f)(i, str + i);
			i++;
		}
	}
}
