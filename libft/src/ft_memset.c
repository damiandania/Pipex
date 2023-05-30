/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:07:41 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:50 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Apunta a la memoria de str y sustituye n cantidad
	de caracteres por c*/

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*pstr;

	i = 0;
	pstr = str;
	while (i < n)
	{
		pstr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
