#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

# define ERROR_ARGUMENT "invalid number of arguments"
# define ERROR_ENV "Error enviroment"
# define ERROR_PIPE "Pipe"
# define ERROR_PID "PID error"

typedef struct s_data
{
	char	**envp;
	char	**av;
	int		ac;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		cmd_nb;
	char	**cmd_arg;
	char	cmd_path;	
	int		child;
	int		*pid;

}		t_data;

int 	error_msg(char *str1, char *str2, char *str3, int erno);
int		error_exit(char *str1, char *str2, int erno, t_data *data);
void	close_fds(t_data *data);




#endif
