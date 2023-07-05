/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:27:44 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:27:45 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	error_exit(char *error)
{
	perror(error);
	exit (1);
}

int	error_msg(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putstr_fd("\n", 2);
	return (erno);
}
