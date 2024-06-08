# get_next_line

# Table of Contents
1. [Description](#description)
2. [Installation Instructions](#installation-instructions)
3. [Usage Instructions](#usage-instructions)
4. [Key Functions](#key-functions)
5. [Contribution Guidelines](#contribution-guidelines)
6. [Acknowledgments](#acknowledgments)
7. [License Information](#license-information)
8. [Contact Information](#contact-information)
9. [Project Development](#project-development)

## Description

"Get_Next_Line" is a reliable and efficient function written in C, designed to read any valid file line by line until the end. This function is particularly useful for developers who need to read content from a file, a standard input, or even from a network connection, line by line.

One of the main features of "Get Next Line" is its focus on robustness and error handling. The function is designed to handle edge cases, such as failed memory allocation or null pointers, preventing segmentation faults and making your code more stable and reliable.

This function is part of a larger project and serves as a cornerstone for many of my applications. By using "Get Next Line", you're not just using a function, but a tool that has been refined and proven in numerous projects.

## Installation Instructions

Before you begin, ensure you have met the following requirements:

1. **Download the library**: You can clone the library from GitHub using the following command in your terminal:
```bash
git clone https://github.com/Vpekdas/get_next_line.git
```

2. **Install a C compiler**: If you don't already have a C compiler installed, you will need one to build and use this library. You can install the [Clang compiler](https://clang.llvm.org).
   
- On a Mac, you should already have Clang installed as part of Xcode Command Line Tools. You can confirm this by running clang --version in your terminal. If it's not installed, you'll be prompted to install it.

- On a Linux machine, use the package manager for your distribution. For example, on Ubuntu:
  ```bash
  sudo apt install clang
  ```

## Usage Instructions

The files get_next_line.c and get_next_line_bonus.c are identical. I have uploaded the same file under two different names to accommodate the requirements of 'Moulinette', an algorithm that automatically grades our projects.

1. **Include the library in your project**: Add the following line at the top of your source code files:
```c
#include "get_next_line.h"
```

2. **Compile your project**: When compiling your project, you can give a buffer size. Here's an example:
```bash
clang -D BUFFER_SIZE=1024 your_program.c get_next_line.c get_next_line_utils.c -o your_project_name
```

## Key Functions
Here are some of the key functions provided by this library:

- `char	*get_next_line(int fd)`: This function returns a line read from a file descriptor each time it's called. If there are no more lines to read, it returns NULL.
```c
char *get_next_line(int fd)
{
static char *buffer[10496]; // Buffer to store the data read from the file. This is a char ** to allow reading from multiple file descriptors simultaneously.
    char *line; // String to store the line to be returned

    // Check for invalid file descriptor or buffer size
    if (fd == -1 || BUFFER_SIZE <= 0)
        return (NULL);

    // Read from the file descriptor into the buffer
    buffer[fd] = read_fd(fd, buffer[fd]);

    // If there's nothing more to read, return NULL
    if (!buffer[fd])
        return (NULL);

    // Get the next line from the buffer
    line = ft_line(buffer[fd]);

    // Update the buffer to remove the line that was just read
    buffer[fd] = ft_remaining_char_buffer(buffer[fd]);

    // Return the line
    return (line);
}
```
* The first step is to read the file in chunks, each of size equal to the buffer size, and then concatenate these chunks with the previously read line. On the first call, a line of 1 byte is allocated with calloc. If a newline character (\n) is found in the buffer, the reading process stops and we proceed to the next step.
```C
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
			free(line);
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
```
* The second step involves receiving the concatenated string from the previous function. We then count characters until a newline character (\n) is encountered, which gives us the length of the string to allocate with malloc. After that, we copy characters until we reach a \n.

```c
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
```
* The final step is to update the static pointer buffer. We will update the buffer with characters that come after the newline character (\n).
```c
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
```

## Acknowledgments

I would like to express my deepest appreciation to all those who provided the possibility to complete this project. A special gratitude I give to the contributors of the following tester programs:

[gnlTester](https://github.com/Tripouille/gnlTester)

This tester programs were instrumental in the development process. They not only helped me identify and correct errors quickly, but also introduced me to new testing methodologies and considerations I hadn't previously encountered. Their insights and expertise contributed significantly to the completion of this project.

## Contribution Guidelines

I welcome contributions from everyone. Here are some guidelines to follow:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/get_next_line.git
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on. Do not make changes directly on the master branch
```bash
git checkout -b your-branch-name
```

4. **Make your changes**: Make your changes in the new branch. Ensure your code follows the [norminette](https://github.com/42School/norminette).

5. **Commit your changes**: Commit your changes regularly with clear, descriptive commit messages.
```bash
git commit -m "Your commit message"
```

6. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

7. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.
Please note that this project has a code of conduct, and contributors are expected to adhere to it. Any contributions you make are greatly appreciated.

## License Information

This project is licensed under the [MIT License](LICENSE).

The MIT License is a permissive license that is short and to the point. It lets people do anything they want with your code as long as they provide attribution back to you and don’t hold you liable.

For the full license text, see the [LICENSE](LICENSE) file.

## Contact Information

If you have any questions, issues, or if you want to contribute, feel free to reach out to me:

- GitHub: [@Vpekdas](https://github.com/Vpekdas)
- Discord: Captain-Plouf#7811

## Project Development

This project started as a simple tool for personal use and is evolving into a full-fledged library. While it has been a solo endeavor so far, contributions from the community are welcome and appreciated.

### Current Status

The project is currently complete and not in active development. However, maintenance and updates will be done as needed.

### Future Plans

Plans for future development include adding more functions, improving performance, and expanding the documentation.

### Known Issues

There are currently no known issues. If you find a bug, please report it in the [issue tracker](https://github.com/Vpekdas/get_next_line/issues).

### Contributing

Contributions are always welcome! See the [Contribution Guidelines](#contribution-guidelines) for more information.
