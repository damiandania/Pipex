/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:32:58 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_type_x(unsigned int nb, const char format)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (len = (write(1, "0", 1)));
	else if (nb >= 16)
	{
		len += ft_type_x(nb / 16, format);
		len += ft_type_x(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			len = ft_type_c(nb + '0');
		else
		{
			if (format == 'x')
				len += ft_type_c(nb - 10 + 'a');
			if (format == 'X')
				len += ft_type_c(nb - 10 + 'A');
		}
	}
	return (len);
}
