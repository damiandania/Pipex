/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:13:19 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:00 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Compara n cantidad de caracteres entre str1 y str 2 y su
	retorno es la diferencia entre el primer caracter que no
	sea igual*/

#include "../includes/libft.h"

int	ft_strncmp(const char *str1, const char*str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0'
		&& str2[i] != '\0' && i < (n - 1))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
