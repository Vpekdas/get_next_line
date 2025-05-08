# get_next_line

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Contributing](#contributing)
5. [License](#license)

## Description

get_next_line is a project from the 42 Common Core curriculum. It involves implementing a utility function that reads a line from a file descriptor, one line at a time. it can also handle multiple file descriptors simultaneously. It's very usefull in C project in 42 curriculum.

As part of the 42 curriculum, this project comes with strict coding guidelines:
- The standard C library is forbidden, requiring the use of custom code for all tasks.
- A strict rule of 5 functions per file and 25 lines per function is enforced.
- There are restrictions such as no assignments on the same line and a focus on clean, maintainable code.

### Purpose

The get_next_line function works similarly to std::getline in C++, allowing you to read input line by line from a file descriptor. However, unlike std::getline, you are responsible for freeing the returned memory yourself. The function reads characters until a newline (\n) or null terminator (\0) is encountered.

### Technologies used

- C language.
- Make.

### Challenges and Future Features

One of the main challenges in this project was understanding how static variables work in C and how they can be used to retain state between function calls. Managing memory efficiently and handling multiple file descriptors were also key learning points.

I’m not planning to add any new features at this time.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

## Run

The files get_next_line.c and get_next_line_bonus.c are identical. I have uploaded the same file under two different names to accommodate the requirements of 'Moulinette', an algorithm that automatically grades our projects.

1. **Include the library in your project**: Add the following line at the top of your source code files:
```c
#include "get_next_line.h"
```

2. **Compile your project**: When compiling your project, you can give a buffer size. Here's an example:
```bash
clang -D BUFFER_SIZE=1024 your_program.c get_next_line.c get_next_line_utils.c -o your_project_name
```

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/get_next_line/issues).

To contribute, follow these steps:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/get_next_line
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on.
```bash
git checkout -b your-branch-name
```

4. **Commit your changes**: Commit your changes.
```bash
git commit -m "Your commit message"
```

5. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

6. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.

## License

This project is licensed under the [MIT License](LICENSE).
