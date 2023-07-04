#include "../includes/pipex.h"

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc(int nmemb, int size)
{
	void	*res;

	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*res;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	return (res);
}
