/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:10:57 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:57 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Crea una subcadena de caracteres comenzando desde start y terminando en
	len con su respectivo '\0'*/

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*d;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (i < len && (start < ft_strlen(s) && s[start + i] != '\0'))
		i++;
	d = malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	while (j < i && start < ft_strlen(s))
	{
		d[j] = s[start];
		start++;
		j++;
	}
	d[j] = '\0';
	return (d);
}
