
#include "../includes/pipex.h"

static char	*get_init_path(char **env)
{
	int		i;
	char	*keyword;
	char	*initial_p;

	initial_p = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		keyword = ft_strnstr(env[i], "PATH=", 5);
		if (keyword)
		{
			initial_p = ft_substr(env[i], 5, (ft_strlen(env[i]) - 5));
			break ;
		}
		i++;
	}
	return (initial_p);
}

static char	**make_tab_of_paths(char **env)
{
	char	*initial_p;
	char	**long_path;
	char	*tmp;
	int		i;

	initial_p = get_init_path(env);
	if (!initial_p)
		return (NULL);
	long_path = ft_split(initial_p, ':');
	free_strs(initial_p, NULL);
	if (!long_path)
		return (NULL);
	i = 0;
	tmp = NULL;
	while (long_path[i] != NULL)
	{
		tmp = long_path[i];
		long_path[i] = ft_strjoin(long_path[i], "/");
		free_strs(tmp, NULL);
		i++;
	}
	if (!long_path)
		return (NULL);
	return (long_path);
}

static char	*find_the_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			free_strs(NULL, paths);
			exit(EXIT_FAILURE);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_strs(cmd_path, NULL);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(t_data *data, char *cmd)
{
	char	**paths;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	paths = make_tab_of_paths(data->env);
	if (!paths)
		return (NULL);
	data->cmd_path = find_the_path(paths, cmd);
	if (!data->cmd_path)
		error_msg(ERR_CMD, ": ", data->cmd_args[0], 1);
	free_strs(NULL, paths);
	return (data->cmd_path);
}
