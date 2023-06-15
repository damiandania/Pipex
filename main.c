#include "pipex.h"

int	pipex(t_data *data)
{
	int	exit_code;

	if (pipe(data->pipe) == -1)
		error_exit("Pipe: ", strerror(errno), 1, data);
	data->child = 0;
	while (data->child < data->cmd_nb)
	{
		data->cmd_arg = ft_split(data->av[data->child + 2], ' ');
		if(!data->cmd_arg)
			error_exit("error", "", 1, data);
		data->cmd_path = get_cmd_path(data->cmd_arg[0], data);
		
		if (!data->cmd_path)
			error_exit();
	}

	return (exit_code);
}

int main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exit_code;

	if (av != 5)
		return (error_msg("Usage: ", ERROR_ARGUMENT, "", 1));
	if (!envp || envp[0][0] == '\0')
		return (error_msg("Usage: ", ERROR_ENV, "", 1));
	init_struc(data, ac, av, envp);
	exit_code = pipex(&data);
	return (exit_code);
}