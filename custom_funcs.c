/**
 * _strcmp - compares two strings and returns the difference
 *
 * Description: compares the ascii value of each char in string
 * @s1: string 1
 * @s2: string 2
 * Return: returns the diffrence of the ascii values
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2 || *s2 > *s1)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _strcat - concatenates two strings
 *
 * Description: finds the end of a strings and copies the string from there
 * @dest: destination array
 * @src: sourse array
 * Return: returns the destination file
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copys array from one pointer to another
 *
 * Description: loops through array and copies each element
 * @dest: pointer to destination file
 * @src: pointer to source file
 * Return: the array
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = src[i];
	return (dest);
}

/**
 * _strlen - prints the length of a string
 * Description: cycles through the array of s until its false
 * @s: input from file
 * Return: returns the length
 */
int _strlen(char *s)
{
	int counter = 0;

	while (s[counter] != 0) /*uses s to create an array for the input*/
		counter++;          /*counts every element*/
	return (counter);       /*return end counter8*/
}

/**
 * _strstr - locates a substring in a string
 *
 * Description: finds the matching bytes of substring in string
 * @haystack: pointer to the string to search in
 * @needle: pointer to the substring of searched for bytes
 * Return: the matched bytes otherwise null
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *Begin = haystack;
		char *pattern = needle;

		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}
		if (!*pattern)
			return (Begin);
		haystack = Begin + 1;
	}
	return (0);
}
