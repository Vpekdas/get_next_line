/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:43:04 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/15 15:41:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_count_len_line(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str)
	{
		if (*str != '\n')
		{
			count++;
			str++;
		}
		else
			return (count);
	}
	return (count);
}

char	*ft_read_fd(int fd, char *tab)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!tab)
			tab = ft_strjoin("", buffer);
		tab = ft_strjoin(tab, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (tab);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	line = ft_calloc(ft_count_len_line(str) + 2, 1);
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i] = '\n';
	if (str[i] && str[i] == '\0')
		line[i] = '\0';
	return (line);
}

char	*ft_next_line(char	*str)
{
	int		index_str;
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	index_str = ft_count_len_line(str);
	line = ft_calloc(ft_strlen(str) - ft_count_len_line(str) + 1, 1);
	if (!line)
		return (NULL);
	if (str[index_str])
		index_str++;
	while (str[index_str])
	{
		line[i++] = str[index_str++];
	}
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}	
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	if (!*line || !buffer)
		return (NULL);
	return (line);
}

int	main () {
	int fd = open("test.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
}

