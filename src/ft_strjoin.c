#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size;
	char	*res;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < ft_strlen(s1) || i < ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		if (i < ft_strlen(s2))
			res[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}
