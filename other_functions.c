#include "monty.h"

/**
 * rtrim - Removes trailing characters from a string
 * @str: Pointer to the string
 * @chars: Characters to be removed
 *
 * Return: Pointer to the trimmed string
 */
char *rtrim(char *str, const char *chars)
{
	int i;

	i = strlen(str) - 1;
	while (i >= 0 && strchr(chars, str[i]) != NULL)
		i--;

	str[i + 1] = '\0';

	return (str);
}
