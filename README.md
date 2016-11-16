# get_next_line_42

The goal of this project is to code a function "get_next_line" that will allow a user to read a file
one line at a time. The project is implemented using one static variable, supports switching among
multiple file descriptors between function calls, and accomodates a specified buffer size.

Each call of get_next_line takes the address of a pointer to the first character in a string, which address is updated
with the next line of a file. The allowed functions for this project are read, malloc, and free. This project relies on
the libft created previously, with several function additions specific to this project, especially the particular linked list
structure implemented.

## Implementation

The project is implemented using a static linked list, each node of which represents an active file descriptor
(in this context, a file opened for reading that has not been read until the end of this file). When called the
function searches the static list for the file descriptor input as a parameter. If the file descriptor is not found, 
a new node is created. The char * storage variables (s & index) held in each node of the list keep track of the data read
from the file. The function will call read until a newline character is found, at which time the function duplicates the
string until the newline character, frees allocated memory, and returns 1 upon success.

## Authors

* **Robert Nowell** (https://github.com/robertnowell)

## Acknowledgments

* This project was completed at School 42, Fremont
