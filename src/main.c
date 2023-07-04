#include "../includes/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	main(int arc, char **arv, char **env)
{
	t_data	data;
	int		exit_code;

	if (arc < check_heredoc(arv[1], &data))
		return (msg(ERR_ARG));
	if (!env || env[0][0] == '\0')
		error_msg(ERR_ENV);
	init(&data, arc, arv, env);
	exit_code = pipex(&data);
	return (exit_code);
}
