# get_next_line - Reading a line from a fd is way too tedious

```
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/[TomekK]
*******************************************************************************
```


Ahoy, fellow coders! Welcome to `get_next_line`, my third expedition at Ecole 42. In this project, I've delved into the world of file input/output in C, crafting a versatile function that can read multiple file descriptors simultaneously.

## Overview

`get_next_line` is a function designed to read a line from a file descriptor and handle multiple file descriptors concurrently. It utilizes static variables to maintain the state between successive calls, allowing for efficient and seamless reading of text from various sources. Importantly, if the file is not too large, the function can read an entire file descriptor over multiple calls.

## Key Features

- **Simultaneous Reading:** Read from multiple file descriptors without losing track of each file's position.
- **Dynamic Buffering:** Dynamically allocate memory for each line, accommodating variable line lengths.
- **Sequential File Reading:** If the file is not too large, read an entire file descriptor over multiple calls.
- **Customizable Buffer Size:** Define the buffer size during compilation with `-D BUFFER_SIZE=N`.
- **No Memory Leaks:** Carefully manage memory allocation to ensure there are no memory leaks during execution.

## Getting Started

To use `get_next_line`, follow these instructions:

### Prerequisites

Before you begin, ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/).

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/Vpekdas/get_next_line
    ```

2. Navigate to the project directory:

    ```bash
    cd get_next_line
    ```

3. Compile the project with a custom buffer size (e.g., 42) using `cc`:

    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
    ```

    Replace `42` in `-D BUFFER_SIZE=42` with your desired buffer size.

## Usage

1. Include the `get_next_line.h` header file in your source files:

    ```c
    #include "get_next_line.h"
    ```

2. Call `get_next_line` function in your code to read lines from file descriptors:

    ```c
    #include "get_next_line.h"

    int main() {
        int fd1 = open("file1.txt", O_RDONLY);
        int fd2 = open("file2.txt", O_RDONLY);

        char *line1;
        char *line2;

        while (get_next_line(fd1, &line1) > 0) {
            // Process lines as needed...
            free(line1);
        }

        while (get_next_line(fd2, &line2) > 0) {
            // Process lines as needed...
            free(line2);
        }

        close(fd1);
        close(fd2);

        return 0;
    }
    ```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
