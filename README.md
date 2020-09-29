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
- ls
- cat
- date
- rm
- mkdir

System calls used:
- fork(): to help in execution of external commands
- execv() : to execute binary files of external commands
- waitpid() : to make the parent process wait until the child process is finished.
