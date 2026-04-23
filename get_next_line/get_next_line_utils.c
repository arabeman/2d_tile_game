/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:13:43 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:49 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*pointer;

	s1_len = (unsigned int)ft_strlen(s1);
	s2_len = (unsigned int)ft_strlen(s2);
	i = 0;
	j = 0;
	pointer = (char *)malloc((s1_len + s2_len) + 1);
	if (!pointer)
		return (NULL);
	while (i < s1_len)
	{
		pointer[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		pointer[i++] = s2[j++];
	}
	pointer[i] = '\0';
	return (pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pointer;
	unsigned int	s_len;
	unsigned int	i;

	s_len = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		len = 0;
	if (len > s_len)
		len = (unsigned int)ft_strlen(s + (start));
	if ((s_len - start) < len)
		len = s_len - start;
	pointer = malloc(len + 1);
	i = 0;
	if (!pointer)
		return (NULL);
	while ((s[i] != '\0') && (i < len))
	{
		pointer[i] = s[start];
		start++;
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

char	*ft_strdup(char *src)
{
	int				i;
	unsigned int	len;
	char			*pointer;

	i = 0;
	len = ft_strlen(src);
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	while (src[i] != '\0')
	{
		pointer[i] = src[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
