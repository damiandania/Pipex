/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:26:03 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/07 14:10:34 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exit_code;

	if (ac < check_heredoc(av[1], &data))
		return (msg(ERR_ARG, "", 1));
	if (!envp || envp[0][0] == '\0')
		return (msg(ERR_ENV, "", 1));
	init(&data, ac, av, envp);
	exit_code = pipex(&data);
	return (exit_code);
}
