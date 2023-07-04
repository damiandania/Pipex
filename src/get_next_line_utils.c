
#include "../includes/pipex.h"

int	some_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

int	find_nl(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

size_t	ft_str_len(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}
