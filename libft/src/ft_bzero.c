/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:56:03 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:57 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	La función bzero() pone a cero los primeros n bytes del área de bytes que
	comienza en s y el retorno es nada */

#include "../includes/libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*pstr;

	i = 0;
	pstr = str;
	while (i < n)
	{
		pstr[i] = 0;
		i++;
	}
}
