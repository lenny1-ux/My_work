#include "shell.h"

/**
 **_strncpy - To copy a thread string.
 *@des: Destination string being copied.
 *@src: string source
 *
 *@n: characters to be copied
 *Return: string concatenated
 */

char *_strncpy(char *des, char *src, int n)
{
	int x, y;
	char *s = des;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		des[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (x < n)
		{
			des[y] = '\0';
			y++;
		}
	}
	return (s);
}

/**
 **_strncat - To concatenate 2 strings
 *@des: 1 string
 *@src: string two being concatenated
 *
 *@n: Total bytes to be used optimally
 *Return: strings concatenated
 */
char *_strncat(char *des, char *src, int n)
{
	int x, y;
	char *s = des;

	x = 0;
	y = 0;
	while (des[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		des[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
		des[x] = '\0';

	return (s);
}

/**
 **_strchr - To locate characters in a string line
 *@s: parsed strings
 *@a: characters being searched for
 *Return: pointer (s) to the allocated mem size s
 *
 */
char *_strchr(char *s, char a)
{
	do {
		if (*s == a)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

