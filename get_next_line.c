/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:57:27 by jsauvain          #+#    #+#             */
/*   Updated: 2022/04/27 11:45:22 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s, int n)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	else
	{
		if (n == 0)
		{
			while (s[i])
				i++;
			return (i);
		}
		while (s[i] != '\n')
			i++;
	}
	i++;
	return (i);
}

char	*strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc((ft_strlen(dst, 0) + ft_strlen(src, 0) + 1), sizeof(char));
	if (new == NULL)
		return (new);
	if (dst != NULL)
	{
		while (dst[j])
			new[i++] = dst[j++];
		j = 0;
	}
	ft_free(&dst, &src, 1);
	while (src[j])
		new[i++] = src[j++];
	new[i] = '\0';
	return (new);
}

char	*get_first_line(char *line, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (dst_checked(dst) == 1)
	{
		line = ft_calloc((ft_strlen(dst, 1) + 1), sizeof(char));
		if (line == NULL)
			return (line);
		while (dst[j] != '\n')
			line[i++] = dst[j++];
		line[i++] = '\n';
	}
	else
	{
		line = ft_calloc((ft_strlen(dst, 0) + 1), sizeof(char));
		if (line == NULL)
			return (line);
		while (dst[j])
			line[i++] = dst[j++];
	}
	line[i] = '\0';
	return (line);
}

char	*modify_dst(char *dst, char *line)
{
	char	*tmp;
	char	*temp;

	tmp = ft_calloc(1, sizeof(char));
	if (tmp == NULL)
		return (tmp);
	temp = dst + ft_strlen(line, 0);
	tmp = strjoin(tmp, temp);
	ft_free(&dst, &line, 1);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*dst = NULL;
	char		*line;

	line = NULL;
	dst = ft_read(dst, fd);
	if (dst == NULL || dst[0] == 0)
		return (NULL);
	else if (dst_checked(dst) == 1)
	{
		line = get_first_line(line, dst);
		if (line == NULL)
			return (0);
		dst = modify_dst(dst, line);
		return (line);
	}
	else if (ft_strlen(dst, 0) > 0)
	{
		line = get_first_line(line, dst);
		if (line == NULL)
			return (line);
		dst = modify_dst(dst, line);
		return (line);
	}
	ft_free(&dst, &line, 1);
	return (line);
}
