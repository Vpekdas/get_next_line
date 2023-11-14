#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		i;
	int			bytes;

	bytes = 0;
	buffer = NULL;
	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		i = 0;
	}
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE + 1);
		if (buffer[i] == '\n')
		{
			line = ft_strdup(buffer);
			i++;
			return (line);
		}
		if (buffer[i] == '\0')
			return (NULL);
		else
		i++;
	}
}
int	main () {
	int fd = open("test.txt", O_RDONLY);
	char	*line;
	
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
}