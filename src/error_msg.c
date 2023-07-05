#include "../includes/pipex.h"

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, &(*s), 1);
		s++;
	}
}

void	msg_pipe(char *arg)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
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
