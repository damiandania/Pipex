/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:21 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:31:22 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_ENV			"error: environment variable not found.\n"
# define ERR_ARG			"error: invalid number of arguments.\n"
# define ERR_INFILE			"infile."
# define ERR_OUTFILE		"outfile."
# define ERR_PIPE			"error creating pipe.\n"
# define ERR_HEREDOC_TMP	"error creating temporary heredoc file.\n"
# define ERR_HEREDOC_READ	"error reading input for here_doc.\n"
# define ERR_CMD			"command not found"
# define ERR_PID			"error process id.\n"
# define ERR_EXEC			"error executing command.\n"
# define ERR_FORK			"error creating child process.\n"

typedef struct s_data
{
	char	**env;
	char	**arv;
	char	*cmd_path;
	char	**cmd_args;
	int		arc;
	int		infile_fd;
	int		outfile_fd;
	int		in;
	int		out;
	int		cmd_nbr;
	int		child;
	int		*pid;
	int		*pipe;
	int		heredoc;
}			t_data;

//		Initialization
void	init(t_data *data, int arc, char **arv, char **env);

//		Heredoc
int		check_heredoc(char *arg, t_data *data);
void	here_doc(char *str, t_data *data);

//		Pipex
int		pipex(t_data *data);

//		Close fds
void	close_all_fds(t_data *data);
void	close_used_fds(t_data *data);
void	close_unused_fds(t_data *data);

//		Command path
char	*get_cmd_path(t_data *data, char *cmd);

//		GNL
int		get_next_line(int fd, char **line, int val);
size_t	ft_str_len(const char *s);
int		find_nl(char *str);
int		some_error(char *str);

//		Utils
int		ft_strlen(const char *s);
void	free_strs(char *str, char **strs);
void	*ft_malloc_zero(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);

char	**ft_split(char const *str, char c);
char	*ft_strnstr(const char *big, const char *little, int len);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(int nb, int size);

//		Error message
void	error_exit(char *error);
int		error_msg(char *str1, char *str2, char *str3, int erno);
void	msg_pipe(char *arg);
void	ft_putstr_fd(char *s, int fd);

#endif
