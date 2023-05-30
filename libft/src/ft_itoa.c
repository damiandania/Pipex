/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:50 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:42:03 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Crea una string aparti de un int y al final su respectivo '\0'

#include "../includes/libft.h"

static int	ft_num_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_num_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		len--;
		str[len] = ft_sign(n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
