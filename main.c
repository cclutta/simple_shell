#include "main.h"
/**
* exec_command - executes commands
* @comm: to be executed
*
* Return: void
*/
void exec_command(char *comm)
{
	pid_t pid;
	char path[128] = "";
	char *argv[3];
	char exit_c[5] = "exit";

	if (strcmp(exit_c, comm) == 0)
	{
	printf("Goodbye");
	exit(1);
	}

	strcat(path, comm);

	argv[0] = path;
	argv[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		printf("\nfailed fork");
		return;
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) < 0)
		{
			printf("\nCcould not execute command\n");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}

/**
* get_null_bytes - get the null bytes
* @str: string
* @index: the index
*
* Return: void
*/
void get_null_bytes(char *str, unsigned int index)
{
	str[index] = '\0';
}

/**
* main - main entry point of progran
*
* Return: int
*/
int main(void)
{
char *buffer;
size_t bufsize = 32;
int chars;

buffer = (char *)malloc(bufsize * sizeof(char));

if (buffer == NULL)
{
printf("Error");
exit(1);
}


while (1)
{
	printf("$- ");
	chars = getline(&buffer, &bufsize, stdin);
	if (chars == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	get_null_bytes(buffer, chars - 1);
	exec_command(buffer);
}
	free(buffer);
	return (0);
}
