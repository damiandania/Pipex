#include "../includes/pipex.h"

static void	open_here_doc_tmp(t_data *data)
{
	data->in_fd = open(".heredoc.tmp", O_RDONLY);
	if (data->in_fd < 0)
	{
		unlink(".heredoc.tmp");
		error_msg(ERR_HEREDOC_TMP);
	}
}

int	check_heredoc(char *arg, t_data *data)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		data->heredoc = 1;
		return (6);
	}
	else
	{
		data->heredoc = 0;
		return (5);
	}
}

void	here_doc(char *str, t_data *data)
{
	int		file;
	char	*buf;

	file = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		error_msg(ERR_HEREDOC_READ);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		if (get_next_line(0, &buf, 0) < 0)
			exit(1);
		if (!ft_strncmp(str, buf, ft_strlen(str) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	get_next_line(0, &buf, 1);
	close(file);
	open_here_doc_tmp(data);
}
