#include "../includes/pipex.h"

static void	connect_io(t_data *data)
{
	int	input;
	int	output;

	close_unused_fds(data);
	input = dup2(data->in, 0);
	if (input == -1)
		exit(EXIT_FAILURE);
	output = dup2(data->out, 1);
	if (output == -1)
		exit(EXIT_FAILURE);
	close_all_fds(data);
}

static void	get_io(t_data *data)
{
	if (data->child == 1)
	{
		data->in = data->in_fd;
		data->out = data->pipe[1];
	}
	else if (data->child == data->cmd_nbr)
	{
		data->in = data->pipe[2 * (data->child - 1) - 2];
		data->out = data->out_fd;
	}
	else
	{
		data->in = data->pipe[2 * (data->child - 1) - 2];
		data->out = data->pipe[2 * data->child - 1];
	}
}

static void	child(t_data *data)
{
	int	exv_code;

	get_io(data);
	connect_io(data);
	if (data->cmd_args == NULL || data->cmd_path == NULL)
		exit(EXIT_FAILURE);
	close_used_fds(data);
	exv_code = execve(data->cmd_path, data->cmd_args, data->env);
	if (exv_code == -1)
	{
		messg(data->cmd_args[0], ": ", strerror(errno), 1);
		exit(EXIT_FAILURE);
	}
}

static int	parent(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_all_fds(data);
	exit_code = 1;
	wpid = waitpid(data->pid[data->cmd_nbr - 1], &status, 0);
	if (wpid && WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	free(data->pipe);
	free(data->pid);
	return (exit_code);
}

int	pipex(t_data *data)
{
	int	exit_code;

	if (pipe(data->pipe) == -1)
		error_msg(ERR_PIPE);
	data->child = 1;
	while (data->child <= data->cmd_nbr)
	{
		data->cmd_args = ft_split(data->arv[data->heredoc + data->child + 1], ' ');
		if (!data->cmd_args)
			exit(EXIT_FAILURE);
		data->cmd_path = get_cmd_path(data, data->cmd_args[0]);
		data->pid[data->child] = fork();
		if (data->pid[data->child] == -1)
			error_msg(ERR_FORK);
		else if (data->pid[data->child] == 0)
			child(data);
		free_strs(data->cmd_path, data->cmd_args);
		data->child++;
	}
	exit_code = parent(data);
	return (exit_code);
}
