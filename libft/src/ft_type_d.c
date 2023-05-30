/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:32:19 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:54 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_type_d(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			len = ft_type_s("-2147483648");
			return (len);
		}
		len += ft_type_c('-');
		nb = -nb;
	}
	if (nb / 10)
	{
		len += ft_type_d(nb / 10);
		len += ft_type_d(nb % 10);
	}
	else
		len += ft_type_c(48 + nb);
	return (len);
}
