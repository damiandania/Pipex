/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:20:27 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:39:16 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_find_type(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_type_c(va_arg(arg, int));
	else if (format == 's')
		len += ft_type_s(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_type_p(va_arg(arg, void *));
	else if (format == 'd' || format == 'i')
		len += ft_type_d(va_arg(arg, int));
	else if (format == 'u')
		len += ft_type_u(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_type_x(va_arg(arg, unsigned int), format);
	else if (format == '%')
		len += ft_type_c('%');
	return (len);
}
