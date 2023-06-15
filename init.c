#include "pipex.h"

void    get_input_file(t_data *data)
{
    data->fd_in = open(data->av[1], O_RDONLY);
    if (data->fd_in == -1)
        error_msg(strerror(errno), ": ", data->av[1], 1);
}

void    get_output_file(t_data *data)
{
    data->fd_out = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (data->fd_out == -1)
        error_msg(strerror(errno), ": ", data->av[data->ac - 1], 1);
}

init_clear(t_data *data)
{
    data->ac = 0;
    data->av = NULL;
    data->envp = NULL;
    data->fd_in = -1;
    data->fd_out = -1;
    data->cmd_nb = 0;
    data->cmd_arg = NULL;
    data->cmd_path = NULL;
    data->child = 0;
    data->pipe = NULL;
    data->pid = NULL;
}

void    create_pipes(t_data *data)
{
    int i;

    i = 0;
    while (1 < data->cmd_nb - 1)
    {
        if (pipe(data->pipe + 2 * i) == -1)
            error_exit("Pipe", "", 1, data);
        i++;
    }
}

void    init_struc(t_data *data, int ac, char **av, char **envp)
{
    init_clear(data);
    data->ac = ac;
    data->av = av;
    data->envp = envp;
    data->cmd_nb = ac - 3;
    get_input_file(data);
    get_output_file(data);
    data->pipe = malloc(sizeof(int) * ((data->cmd_nb - 1) * 2));
    if (!data->pipe)
        error_exit("Pipe", "", 1, &data);
    data->pid = malloc(sizeof(int) * (data->cmd_nb + 1));
        error_exit(ERROR_PID, strerror(errno), 1, &data);
    create_pipes(data);
}