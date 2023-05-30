/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:57:09 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	retorna la letra mayuscula equivalente de c*/

#include "../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
