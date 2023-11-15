/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:43:04 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/14 16:10:37 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_count_len(char *str)
{
	int	count;

	count = 0;
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
		buffer[bytes] = '\0';
		if (!tab)
			tab = ft_strjoin("", buffer);
		else
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
	line = ft_calloc(ft_count_len(str) + 2, 1);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		line[i] = '\n';
	}
	return (line);
}

char	*ft_next_line(char	*str)
{
	int		index_str;
	int		i;
	char	*line;

	i = 0;
	index_str = ft_count_len(str) + 1;
	line = ft_calloc(ft_strlen(str) - ft_count_len(str) + 1, 1);
	while (str[index_str])
	{
		line[i] = str[index_str];
		i++;
		index_str++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_read_fd(fd, buffer);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
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
}

