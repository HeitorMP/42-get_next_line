
# 42-get_next_line

### This 42 project consists of writing a function that returns a line read from a file descriptor!

- Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when reading from the standard input.
- Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
- Add all the helper functions you need in the get_next_line_utils.c file
- Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n It will define the buffer size for read(). The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
- You will compile your code as follows (a buffer size of 42 is used as an example):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
- We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file. 
- We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

## Bonus part:

- Develop get_next_line() using only one static variable.
- Your get_next_line() can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.










## What i learned:
 - Static variables
 - File manipulation
 - C programming
 - Basic algorithms

## Installation and Running

This project will not generate any lib or executable, just the function that will be added to [libft](https://github.com/HeitorMP/42-libft)! 


    
## Useful links

- [Static variable](https://en.wikipedia.org/wiki/Static_variable)
- [File manipulation - open](https://man7.org/linux/man-pages/man2/open.2.html)
- [File manipulation - read](https://man7.org/linux/man-pages/man2/read.2.html)



