/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:55:59 by zel-yama          #+#    #+#             */
/*   Updated: 2025/01/10 18:49:28 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_str_join(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	all_size;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	all_size = ft_strlen((s1)) + ft_strlen(s2);
	result = (char *) malloc ((all_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

int	ft_strchr(const char *s, int c)
{
	char	tp;
	int		i;

	i = 0;
	tp = (char) c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == tp)
			return (1);
		else
			i++;
	}
	if (s[i] == tp)
		return (1);
	return (0);
}

char	*free_and_join(char *store, char *s)
{
	char	*str;

	str = ft_str_join(store, s);
	free(store);
	store = NULL;
	return (str);
}
