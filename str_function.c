#include "monty.h"

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the new string
 */
char *_strdup(char *str)
{
	char *new;
	int i, size = 0;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
