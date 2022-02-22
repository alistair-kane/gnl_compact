/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:08:24 by alkane            #+#    #+#             */
/*   Updated: 2022/02/22 07:15:52 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*return_free(char *line)
{
	free(line);
	return (NULL);
}

static void	bufjoiner(char **line, char *buf)
{
	char			*dst;
	unsigned int	total_size;
	int				i;
	int				j;

	total_size = ft_strlen(*line) + ft_strlen(buf) + 1;
	dst = ft_calloc(total_size, sizeof (char));

	i = -1;
	while (line[0][++i])
		dst[i] = line[0][i];
	free(line[0]);
	
	j = 0;
	while ((buf[j] != '\n') && buf[j])
		dst[i++] = buf[j++];
	if (buf[j] == '\n')
		dst[i] = '\n';
	*line = dst;
}

static void	memory_shift(char *buf)
{
	int		seg_1;
	int		seg_2;

	seg_1 = ft_strchr(buf) + 1;
	seg_2 = ft_strlen(buf) - seg_1;
	ft_memmove(buf, &buf[seg_1], seg_2);
	ft_memset(&buf[seg_2], seg_1);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	while ((ft_strchr(buf) == -1))
	{
		if (*buf)
			bufjoiner(&line, buf);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0 && !(*line))
			return (return_free(line));
		buf[read_bytes] = '\0';
		if ((ft_strchr(buf) == -1) && read_bytes < BUFFER_SIZE)
		{
			bufjoiner(&line, buf);
			ft_memset(buf, 1);
			return (line);
		}
	}
	bufjoiner(&line, buf);
	memory_shift(buf);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int	fd;
// 	char *res;
// 	int i;

// 	fd = open("41_with_nl", O_RDWR);
// 	i = 0;
// 	while (i < 9)
// 	{
// 		res = get_next_line(fd);
// 		printf("line %i: %s",i, res);
// 		i++;
// 	}
// }