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

char	*ft_read_fd(int fd, char *buffer)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (bytes < 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n'))
		{
			while (buffer[i] && buffer[i] != '\n')
			{
				i++;
			}
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

}

int	main () {
	int fd = open("test.txt", O_RDONLY);
	char	*line;
	
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
}

