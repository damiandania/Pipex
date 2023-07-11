/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:36 by mcombeau          #+#    #+#             */
/*   Updated: 2023/07/11 17:38:37 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "get_next_line.h"

# define ERR_ENV			"error: environment variable not found.\n"
# define ERR_ARG			"error: invalid number of arguments.\n"
# define ERR_INFILE			"no such file or directory: "
# define ERR_OUTFILE		"openning outfile: "
# define ERR_PIPE			"error creating pipe: "
# define ERR_CMD_EMPTY		"command not valid\n"
# define ERR_HEREDOC		"here_doc: "
# define ERR_HEREDOC_TMP	"error creating temporary heredoc file.\n"
# define ERR_HEREDOC_READ	"error reading input for here_doc.\n"
# define ERR_CMD			"command not found: "
# define ERR_PID			"error process id: "
# define ERR_EXEC			"error executing command: "
# define ERR_FORK			"error creating child process: "

typedef struct s_data
{
	char	**envp;
	char	**av;
	int		ac;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		nb_cmds;
	int		child;
	int		*pids;
	char	**cmd_options;
	char	*cmd_path;
}		t_data;

//		Initialization
void	init(t_data *data, int ac, char **av, char **envp);

//		Heredoc
void	get_heredoc(t_data *data);
int		check_heredoc(char *arg, t_data *data);

//		Pipex
int		pipex(t_data *data);

//		Get path commands
char	*get_cmd(char *cmd, t_data *data);

//		Error exit message
void	exit_error(int error_status, t_data *data);
int		msg(char *str1, char *str2, int erno);
void	close_fds(t_data *data);
void	free_strs(char *str, char **strs);

//		Utils
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
