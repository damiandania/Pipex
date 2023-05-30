/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:20:50 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 15:04:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Imprime una cadenad de caracteres str segun el formato de fd

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	ret;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ret = write (fd, &s[i++], 1);
			if (ret == -1)
			{
				perror("write error");
				exit(1);
			}
		}
	}
}
