/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:55:19 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:12 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Retorna un 1 si el int esta en la tabla de ascii */

#include "../includes/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
