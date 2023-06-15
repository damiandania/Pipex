#include "pipex.h"

void	close_fds(t_data *data)
{
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);	
}

int	error_msg(char *str1, char *str2, char *str3, int erno)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putchar_fd('\n', 2);
	return (erno);
}

int	error_exit(char *str1, char *str2, int erno, t_data *data)
{
	if (data)
	{
		close_fds(data);
		if (data->pipe != NULL)
			free(data->pipe);
		if (data->pid != NULL)
			free(data->pid);
	}
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putchar_fd('\n', 2);
	exit(erno);
}