/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:29 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:52 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	compara 2 char, o 2 ints,
 *	si if Return value < 0 then it indicates str1 is less than str2.
	if Return value > 0 then it indicates str2 is less than str1.
	if Return value = 0 then it indicates str1 is equal to str2*/

#include "../includes/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (pstr1[i] != pstr2[i])
			return (pstr1[i] - pstr2[i]);
		i++;
	}
	return (0);
}
