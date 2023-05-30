/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:27:06 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Toma un char y lo trnaforma en un int, este puede tener varios
	espacios al comienzo, un solo signo y para al encontrar algun
	digio que no sea numerico */

#include "../includes/libft.h"

static size_t	ft_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		ret;
	int		sig;

	i = ft_whitespace(str);
	sig = 1;
	if (str[i] == '-')
		sig = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret * sig);
}
