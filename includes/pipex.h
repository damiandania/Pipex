

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define ERR_ENV			"Environment variable not found.\n"
# define ERR_ARG			"Invalid number of arguments.\n"
# define ERR_INFILE			"Infile.\n"
# define ERR_OUTFILE		"Outfile.\n"
# define ERR_PIPE			"Error creating pipe.\n"
# define ERR_HEREDOC_TMP	"Error creating or accessing the temporary heredoc file.\n"
# define ERR_HEREDOC_READ	"Error reading input for here_doc.\n"
# define ERR_CMD			"Command not found.\n"
# define ERR_PID			"Error process id\n"
# define ERR_EXEC			"Error executing command.\n"
# define ERR_FORK			"Error creating child process.\n"

typedef struct s_data
{
	char	**env;
	char	**arv;
	char	*cmd_path;
	char	**cmd_args;
	int		arc;
	int		in_fd;
	int		out_fd;
	int		in;
	int		out;
	int		cmd_nbr;
	int		child;
	int		*pid;
	int		*pipe;
	int		heredoc;
}			t_data;

//		Init
void	init(t_data *data, int arc, char **arv, char **env);

//		Heredoc
int		check_heredoc(char *arg, t_data *data);
void	here_doc(char *str, t_data *data);

//		Pipex
int		pipex(t_data *data);

//		Close_fds
void		close_all_fds(t_data *data);
void		close_used_fds(t_data *data);
void		close_unused_fds(t_data *data);

//		Cmd_path
char		*get_cmd_path(t_data *data, char *cmd);

//		GNL
int	get_next_line(int fd, char **line, int val);
size_t	ft_str_len(const char *s);
int	find_nl(char *str);
int	some_error(char *str);


int			msg(char *error);
int			ft_strlen(const char *s);
int			messg(char *str1, char *str2, char *str3, int erno);
int			ft_strncmp(const char *s1, const char *s2, int n);

void		msg_pipe(char *arg);
void		error_msg(char *error);
void		ft_bzero(void *s, int n);
void		*ft_calloc(int nmemb, int size);
void		connect_in_out_to_stand(t_data *data);
void		free_strs(char *str, char **strs);
void		*ft_malloc_zero(size_t count, size_t size);

char		*ft_strdup(const char *s1);
char		**ft_split(char const *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, int start, int len);
char		*ft_strnstr(const char *big, const char *little, int len);

#endif
