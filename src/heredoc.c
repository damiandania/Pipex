/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:33:36 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:33:37 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	open_here_doc_tmp(t_data *data)
{
	data->infile_fd = open(".heredoc.tmp", O_RDONLY);
	if (data->infile_fd < 0)
	{
		unlink(".heredoc.tmp");
		error_exit(ERR_HEREDOC_TMP);
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
		error_exit(ERR_HEREDOC_READ);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		if (get_next_line(0, &buf, 0) < 0)
			exit(1);
		if (!ft_strncmp(str, buf, ft_strlen(str) + 1))
			break ;
		ft_putstr_fd(buf, file);
		free(buf);
	}
	free(buf);
	get_next_line(0, &buf, 1);
	close(file);
	open_here_doc_tmp(data);
}
