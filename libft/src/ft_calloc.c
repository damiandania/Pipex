/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:48:21 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:17 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Asigna el número especificado de bytes y los inicializa a
//	cero(0)

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == 0 || size == 0)
		return (malloc(0));
	ft_memset((unsigned char *)ptr, 0, nmemb * size);
	return (ptr);
}
