/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:27:16 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:27:17 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	create_pipes(t_data *data)
{
	int	i;

	i = 1;
	while (i < (data->cmd_nbr - 1))
	{
		if (pipe(data->pipe + (2 * i)) == -1)
			error_exit(ERR_PIPE);
		i++;
	}
}

static void	get_input(t_data *data)
{
	if (!ft_strncmp("here_doc", data->arv[1], 9))
		here_doc(data->arv[2], data);
	else
	{
		data->infile_fd = open(data->arv[1], O_RDONLY);
		if (data->infile_fd == -1)
			error_msg(strerror(errno), ": ", data->arv[1], 1);
	}
}

static void	get_output(t_data *data)
{
	if (data->heredoc)
		data->outfile_fd = open(data->arv[data->arc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
	{
		data->outfile_fd = open(data->arv[data->arc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->outfile_fd == -1)
			error_msg(strerror(errno), ": ", data->arv[data->arc - 1], 1);
	}
}

static void	init_struc(t_data *data)
{
	data->arc = 0;
	data->arv = NULL;
	data->env = NULL;
	data->cmd_path = NULL;
	data->cmd_args = NULL;
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->cmd_nbr = -1;
	data->child = 0;
	data->pipe = NULL;
	data->pid = NULL;
}

void	init(t_data *data, int arc, char **arv, char **env)
{
	int	i;

	init_struc(data);
	data->arc = arc;
	data->arv = arv;
	data->env = env;
	data->cmd_nbr = arc - 3 - data->heredoc;
	get_input(data);
	get_output(data);
	data->pipe = malloc(sizeof(int) * ((data->cmd_nbr - 1) * 2));
	if (!data->pipe)
		error_exit(ERR_PIPE);
	data->pid = malloc(sizeof(int) * (data->cmd_nbr + 1));
	i = 0;
	while (i < data->cmd_nbr)
	{
		data->pid[i] = -1;
		i++;
	}
	if (!data->pid)
		error_exit(ERR_PID);
	create_pipes(data);
}
