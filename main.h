#ifndef FILE_MAIN
#define FILE_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>


void get_null_bytes(char *str, unsigned int index);
void exec_command(char *comm);

#endif
