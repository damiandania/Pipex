/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:34:18 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_put_ptr(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_put_ptr(nb / 16);
		len += ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			len += ft_type_c(nb + '0');
		else
			len += ft_type_c(nb - 10 + 'a');
	}
	return (len);
}

int	ft_type_p(void *nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len += ft_type_s("0x");
	len += ft_put_ptr((unsigned long)nb);
	return (len);
}
