#include "monty.h"

#define MAX_LINE_LENGTH 1024
#define DELIMITER "\n"
/**
 * tokens - a list of tokens separated by spaces.
 * @file: the file
 * Return: the number of tokens separated.
 */


char **tokens(FILE *file)
{
char line[MAX_LINE_LENGTH], *token = NULL, **command = NULL, *ptr;
int i = 0, j, num_tokens = 1;
while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
{
ptr = line;
while (*ptr != '\0')
{
if (strchr(DELIMITER, *ptr) != NULL)
	num_tokens++;
ptr++;
}
}
command = malloc((num_tokens + 1) * sizeof(char *));
if (command == NULL)
{
malloc_error();
return (NULL);
}
rewind(file);
while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
{
token = strtok(line, DELIMITER);
while (token != NULL)
{
command[i] = _strdup(token);
if (command[i] == NULL)
{
malloc_error();
for (j = 0; j < i; j++)
	free(command[j]);

free(command);
return (NULL);
}
token = strtok(NULL, DELIMITER);
i++;
}
}
command[num_tokens] = NULL;
return (command);
}

/**
 * real_tokens - a list of tokens separated by spaces.
 * @line: the line to tokenise from
 * Return: the tokens separated.
 */
char **real_tokens(char *line)
{
	char *token = NULL, *delim = " \t\n", **command = NULL, *ptr = line;
	int i = 0, j, num_tokens = 1;

	if (line == NULL)
		return (NULL);

	while (*ptr != '\0')
	{
		if (strchr(delim, *ptr) != NULL)
		{
			num_tokens++;
		}
		ptr++;
	}

	command = malloc((num_tokens + 1) * sizeof(char *));
	if (command == NULL)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, delim);
	if (token == NULL)
	{
		free(line);
		free(command);
		return (NULL); /* no command entered */
	}
	command[0] = _strdup(token);
	if (command[0] == NULL)
	{
		free(command);
		free(line);
		return (NULL);
	}

	for (i = 1; i < num_tokens; i++)
	{
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			command[i] = _strdup(token);
			if (command[i] == NULL)
			{
				free(line);
				for (j = 0; j < i; j++)
				{
					free(command[j]);
				}
				free(command);
				return (NULL);
			}
		}
		else
		{
			command[i] = NULL; /* initialize token to NULL*/
		}
	}
	command[num_tokens] = NULL;

	free(line);
	return (command);
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 * Return: A pointer to a new string.
*/
char *_itoa(int n)
{
	char buf[15];
	int i = 0;

	if (n == 0)
	{
		buf[i++] = '0';
	}
	else
	{
		while (n != 0)
		{
			buf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[i] = '\0';

	reverse_string(buf, i);
	return (_strdup(buf));
}

/**
 * _strchr - search for a char in a string
 * @p: The char to be searched.
 * @ch: the char to be searched for
 * Return: A pointer to the char
*/
char *_strchr(const char *p, int ch)
{
	char c;

	c = ch;
	for (;; ++p)
	{
		if (*p == c)
			return ((char *)p);
		if (*p == '\0')
			return (NULL);
	}
	/* NOTREACHED */
}

/**
 * reverse_string - Reverse a string.
 * @buf: The string to reverse.
 * @len: The length of the string.
*/
void reverse_string(char *buf, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = buf[start];
		buf[start] = buf[end];
		buf[end] = tmp;
		start++;
		end--;
	}
}
