/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:25:27 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/07 19:50:22 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	redirect_io(int input, int output, t_data *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
		exit_error(1, data);
	if (dup2(output, STDOUT_FILENO) == -1)
		exit_error(1, data);
}

static void	child(t_data *data)
{
	if (data->child == 0)
		redirect_io(data->fd_in, data->pipe[1], data);
	else if (data->child == data->nb_cmds - 1)
		redirect_io(data->pipe[2 * data->child - 2], data->fd_out, data);
	else
		redirect_io(data->pipe[2 * data->child - 2],
			data->pipe[2 * data->child + 1], data);
	close_fds(data);
	if (data->cmd_options == NULL || data->cmd_path == NULL)
		exit_error(1, data);
	if (execve(data->cmd_path, data->cmd_options, data->envp) == -1)
		exit_error(msg(data->cmd_options[0], strerror(errno), 1), data);
}

static int	parent(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fds(data);
	data->child--;
	exit_code = 1;
	while (data->child >= 0)
	{
		wpid = waitpid(data->pids[data->child], &status, 0);
		if (wpid == data->pids[data->nb_cmds - 1])
		{
			if ((data->child == (data->nb_cmds - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		data->child--;
	}
	free(data->pipe);
	free(data->pids);
	return (exit_code);
}

int	pipex(t_data *data)
{
	int		exit_code;

	if (pipe(data->pipe) == -1)
		exit_error(msg(ERR_PIPE, strerror(errno), 1), data);
	data->child = 0;
	while (data->child < data->nb_cmds)
	{
		data->cmd_options = ft_split(data->av[data->child + 2 + data->heredoc],
				' ');
		if (!data->cmd_options[0])
			exit_error(msg(ERR_CMD_EMPTY, "\n", 1), data);
		data->cmd_path = get_cmd(data->cmd_options[0], data);
		data->pids[data->child] = fork();
		if (data->pids[data->child] == -1)
			exit_error(msg(ERR_FORK, strerror(errno), 1), data);
		else if (data->pids[data->child] == 0)
			child(data);
		free_strs(data->cmd_path, data->cmd_options);
		data->child++;
	}
	exit_code = parent(data);
	if (data->heredoc == 1)
		unlink(".heredoc.tmp");
	return (exit_code);
}
