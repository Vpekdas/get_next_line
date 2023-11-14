#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	static ssize_t	i;
	static int		bytes;


	i = 0;
	bytes = 0;
	buffer = NULL;
	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (buffer[i] == '\n')
		{
			line = ft_strdup(buffer);
			i++;
			return (line);
		}
		else if (buffer[i] == '\0')
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
}