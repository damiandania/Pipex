#include "../includes/pipex.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;

	if (!big && !len)
		return (NULL);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > i)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && little[j] == big[i + j] && len > j + i)
				j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
