/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:13:57 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 15:00:31 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Imprime un char segun el formato de fd

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	if (ret == -1)
	{
		perror("write error");
		exit(1);
	}
}
