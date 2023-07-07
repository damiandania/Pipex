/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:21:50 by mcombeau          #+#    #+#             */
/*   Updated: 2023/07/07 14:10:57 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	get_input_file(t_data *data)
{
	if (data->heredoc == 1)
	{
		get_heredoc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY);
		if (data->fd_in == -1)
			exit_error(msg(ERR_HEREDOC, strerror(errno), 1), data);
	}
	else
	{
		data->fd_in = open(data->av[1], O_RDONLY, 644);
		if (data->fd_in == -1)
			msg(ERR_INFILE, data->av[1], 1);
	}
}

static void	get_output_file(t_data *data)
{
	if (data->heredoc == 1)
		data->fd_out = open(data->av[data->ac - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->fd_out = open(data->av[data->ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		msg(strerror(errno), data->av[data->ac - 1], 1);
}

static void	init_struc(t_data *data)
{
	data->envp = NULL;
	data->ac = -1;
	data->av = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->pipe = NULL;
	data->nb_cmds = -1;
	data->child = -1;
	data->pids = NULL;
	data->cmd_options = NULL;
	data->cmd_path = NULL;
}

static void	create_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds - 1)
	{
		if (pipe(data->pipe + 2 * i) == -1)
			exit_error(msg(ERR_PIPE, "", 1), data);
		i++;
	}
}

void	init(t_data *data, int ac, char **av, char **envp)
{
	init_struc(data);
	data->envp = envp;
	data->ac = ac;
	data->av = av;
	get_input_file(data);
	get_output_file(data);
	data->nb_cmds = ac - 3 - data->heredoc;
	data->pids = malloc(sizeof * data->pids * data->nb_cmds);
	if (!data->pids)
		exit_error(msg(ERR_PID, strerror(errno), 1), data);
	data->pipe = malloc(sizeof * data->pipe * 2 * (data->nb_cmds - 1));
	if (!data->pipe)
		exit_error(msg(ERR_PIPE, "", 1), data);
	create_pipes(data);
}
