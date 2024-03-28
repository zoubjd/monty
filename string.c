#include "monty.h"

/**
 * _strlen - function to return the length of the string.
 * @s: the string to be strlen.
 * Return: the length of the string.
*/
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	{
	}

	return (len);
}

/**
 * _strdup - strdup the given string.
 * @str: the string to be strdup.
 * Return: the new string with the given string replaced.
*/

char *_strdup(const char *str)
{
	char *pointer;
	int i = 0, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);

	pointer = malloc(len + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		pointer[i] = str[i];
		i++;
	}
	pointer[len] = '\0';
	return (pointer);
}

/**
 * _strcmp - strcmp function for strings.
 * @str1: the first string to compare.
 * @str2: the second string to compare.
 * Return: strcmp function.
*/
char _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return ((int)str1[i] - (int)(str2[i]));
}

/**
 * _round - round function
 * @number: the number to be rounded
 * Return: the rounded number
*/
int _round(double number)
{
return ((number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5));
}

/**
 * my_isdigit - round function
 * @c: the digit to be checked
 * Return: 0 in case of failure or 1 success
*/
int my_isdigit(int c)
{
return (c >= '0' && c <= '9');
}

