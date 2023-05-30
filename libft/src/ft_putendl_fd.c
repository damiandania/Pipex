/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:40:57 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 18:43:42 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Imprime una cadenad de caracteres str segun el formato de fd
// mas un salto de linea.

#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i++], 1);
		}
	}
	write (fd, "\n", 1);
}
