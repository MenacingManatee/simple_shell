#include "shell.h"
#include <string.h>

/**
 *
 *
 *
 */

char **_strtok(char *line, char *delm)
{
	char *tok, **ptr;
	int i;
	size_t words = 0;

	for (i = 0; line[i]; i++)
	{
		if (line[i] != *delm && (line[i + 1] == *delm || line[i + 1] == '\0'))
				words++;
	}
	line[i - 1] = '\0';

	ptr = malloc(sizeof(char *) * (words + 1));

	if (!ptr)
	{
		printf("Error\n");
		return (0);
	}

	tok = strtok(line, delm);

	for (i = 0; tok != NULL; i++)
	{
		ptr[i] = malloc(strlen(tok) + 1);
		if (!ptr[i])
		{
			for (i -= 1; i >= 0; i--)
				free(ptr[i]);
			exit;
		}
		strcpy(ptr[i], tok);
		tok = strtok(NULL, delm);
	}
	ptr[i] = NULL;

	return (ptr);
}
