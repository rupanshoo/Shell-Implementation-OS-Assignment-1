# OS-Assignment-1
System call and building a shell
Implementing Internal and External System Calls:

Internal Calls implemented-
- cd
  --> ..
- history
- pwd
- echo
- exit

External Calls implemented-
- ls --> -a and -F
- cat
- date
- rm
- mkdir

System calls and functions used:
- fork(): to help in execution of external commands
- execv() : to execute binary files of external commands
- waitpid() : to make the parent process wait until the child process is finished.
- sleep() : causes the calling thread to sleep for the specified number of seconds or till a signal arrives
- fgetc() : gets input a single character at a time and returns the number of characters stored by it.
- strdup() : to duplicate a string
- strtok() : to find tokens in a string using delimiters
- strcpy() : to copy string
- memset(): sets all the characters in an array to the character or value provided
- getcwd() : to get current working directory of the program
- chdir(): to change directory
- strcat() : to concatenate strings
- opendir() : to open a directory
- readdir(): reads a directory
- stat() : returns information about a file.
- S_ISDIR() : to check if it's a directory or not
- closedir() : to close directory
