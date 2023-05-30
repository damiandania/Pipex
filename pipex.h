#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pid
{
	char	**argv;
	char	**env;
	int		argc;

}		t_pid;


#endif
