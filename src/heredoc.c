/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:48:12 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/07 15:39:33 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	get_heredoc(t_data *data)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp_fd == -1)
		exit_error(msg(ERR_HEREDOC, strerror(errno), 1), data);
	line = "";
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strlen(data->av[2]) + 1 == ft_strlen(line)
			&& !ft_strncmp(line, data->av[2], ft_strlen(data->av[2] + 1)))
			close(stdin_fd);
		else
			ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
}
