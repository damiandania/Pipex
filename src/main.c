#include "../includes/pipex.h"

int	main(int arc, char **arv, char **env)
{
	t_data	data;
	int		exit_code;

	if (arc < check_heredoc(arv[1], &data))
		error_exit(ERR_ARG);
	if (!env || env[0][0] == '\0')
		error_exit(ERR_ENV);
	init(&data, arc, arv, env);
	exit_code = pipex(&data);
	return (exit_code);
}
