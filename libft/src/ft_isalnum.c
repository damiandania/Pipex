/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:49 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:15 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Retorna 1 si el int es una letra o un numero*/

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
