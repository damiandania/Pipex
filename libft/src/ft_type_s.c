/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:34:25 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_type_s(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		len = write (1, "(null)", 6);
		return (len);
	}
	while (str[len])
		len += ft_type_c(str[len]);
	return (len);
}
