/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:26:07 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:42:05 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Retorna un 1 si el caracter se puede imprimir*/

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
