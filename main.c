#include "monty.h"

global_t globs;

/**
 * free_globs - frees global variables
 * Return: nothing
 */
void free_globs(void)
{
	free_dlistint(globs.head);
	free(globs.buf);
	fclose(globs.fd);
}
/**
 * _globs - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void _globs(FILE *fd)
{
	globs.lifo = 1;
	globs.count = 1;
	globs.arg = NULL;
	globs.head = NULL;
	globs.fd = fd;
	globs.buf = NULL;
}
/**
 * check_args - checks arguments if true it open the file arg
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: file struct
 */
FILE *check_args(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	char *lines[2] = {NULL, NULL};
	ssize_t nline = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	fd = check_args(argc, argv);
	_globs(fd);
	nline = getline(&globs.buf, &size, fd);
	while (nline != -1)
	{
		lines[0] = strtok(globs.buf, " \t\n");
		if (lines[0])
		{
			f = get_opcode(lines[0]);

			if (!f)
			{
				printf("L%d: unknown instruction %s\n", globs.count, lines[0]);
				free_globs();
				exit(EXIT_FAILURE);
			}
			globs.arg = strtok(NULL, " \t\n");
			f(&globs.head, globs.count);
		}
		nline = getline(&globs.buf, &size, fd);
		globs.count++;
	}
	free_globs();

	return (0);
}
