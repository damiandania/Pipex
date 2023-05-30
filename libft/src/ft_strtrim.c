/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:44:04 by ddania-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:58 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Elimina el contenido al inicio y al final de str segun set

#include "../includes/libft.h"

static int	in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int	i;
	int	j;

	if (!str || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] && in_set(str[i], set))
		i++;
	while (str[j] && in_set(str[j], set))
		j--;
	if (j == -1)
		return (ft_substr(str, i, 0));
	return (ft_substr(str, i, (j - i + 1)));
}
