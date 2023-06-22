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

/**
 * is_integer - Checks if a string represents a valid integer
 * @str: String to check
 * Return: True if the string is a valid integer, otherwise false
 */
bool is_integer(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (false);

	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
