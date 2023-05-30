/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:56:56 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	retorna la letra minuscula equivalente de c*/

#include "../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
