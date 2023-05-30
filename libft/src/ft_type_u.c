/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:33:03 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:52 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbr_len(unsigned	int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*ft_itoa_p(unsigned int nb)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(nb);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (nb != 0)
	{
		nbr[len - 1] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (nbr);
}

int	ft_type_u(unsigned long long nb)
{
	int		len;
	char	*nbr;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		nbr = ft_itoa_p(nb);
		len += ft_type_s(nbr);
		free(nbr);
	}
	return (len);
}
