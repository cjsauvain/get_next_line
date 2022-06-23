/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:32:59 by jsauvain          #+#    #+#             */
/*   Updated: 2022/04/25 16:04:06 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*calloc;
	char	*cast;

	i = 0;
	if (size <= 4294967295 || nmemb <= 4294967295)
	{
		calloc = malloc(nmemb * size);
		cast = calloc;
		if (calloc == NULL)
			return (calloc);
		while (i < nmemb * size)
		{
			cast[i] = 0;
			i++;
		}
		return (calloc);
	}
	return (NULL);
}

int	dst_checked(char *dst)
{
	int	i;

	i = 0;
	if (dst != NULL)
	{
		while (dst[i] && dst != NULL)
		{
			if (dst[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_free(char **src1, char **src2, int n)
{
	if (n == 1)
	{
		if (*src1)
			free(*src1);
		*src1 = NULL;
	}
	else if (n == 2)
	{
		if (*src1)
			free(*src1);
		if (*src2)
			free(*src2);
		*src1 = NULL;
		*src2 = NULL;
	}
}

char	*ft_read(char *dst, int fd)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buf == NULL || BUFFER_SIZE == 0)
		return (NULL);
	while (ret && dst_checked(dst) == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			ft_free(&buf, &dst, 1);
			return (NULL);
		}
		buf[ret] = '\0';
		dst = strjoin(dst, buf);
	}
	ft_free(&buf, &dst, 1);
	return (dst);
}
