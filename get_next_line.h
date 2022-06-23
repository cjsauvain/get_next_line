/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:58:11 by jsauvain          #+#    #+#             */
/*   Updated: 2022/04/27 10:40:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*modify_dst(char *dst, char *line);
char	*get_first_line(char *line, char *dst);
char	*strjoin(char *dst, char *src);
int		ft_strlen(char *s, int n);
void	*ft_calloc(size_t nmemb, size_t size);
int		dst_checked(char *dst);
void	ft_free(char **src1, char **src2, int n);
char	*ft_read(char *dst, int fd);

#endif
