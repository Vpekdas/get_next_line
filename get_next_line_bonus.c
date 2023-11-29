/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:25:23 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/29 12:15:13 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

int	ft_count_len_line(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str && *str != '\n')
	{
		count++;
		str++;
	}
	return (count);
}

char	*read_fd(int fd, char *line)
{	
	int		bytes;
	char	*buffer;

	bytes = 1;
	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin_and_free(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || *buffer == '\0')
		return (NULL);
	line = ft_calloc(ft_count_len_line(buffer) + 2, 1);
	if (!line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_remaining_char_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = ft_count_len_line(buffer);
	j = 0;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10496];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_remaining_char_buffer(buffer[fd]);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main () {

	int	fd1 = open("test1.txt", O_RDONLY);
	int	fd2 = open("test2.txt", O_RDONLY);
	int	fd3 = open("test3.txt", O_RDONLY);

	char*	line1;
	char*	line2;
	char*	line3;
	
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line2 = get_next_line(fd2);
	printf("%s", line2);
	free(line2);
	line3 = get_next_line(fd3);
	printf("%s", line3);
	free(line3);

	printf("%s", get_next_line(0));
}