/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:27:49 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:27:50 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_unused_fds(t_data *data)
{
	int	i;

	if (data->in != data->infile_fd)
		close(data->infile_fd);
	if (data->out != data->outfile_fd)
		close(data->outfile_fd);
	i = 0;
	while (i < ((data->cmd_nbr - 1) * 2))
	{
		if (data->pipe[i] != data->in && data->pipe[i] != data->out)
			close(data->pipe[i]);
		i++;
	}
}

void	close_used_fds(t_data *data)
{
	close(data->in);
	close(data->out);
}

void	close_all_fds(t_data *data)
{
	int	i;

	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	i = 0;
	while (i < (data->cmd_nbr - 1) * 2)
	{
		close(data->pipe[i]);
		i++;
	}
}
