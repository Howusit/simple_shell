#include "shell.h"

/**
 * _strcpy - copies a string
 * @destin: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *_strcpy(char *destin, char *src)
{
int i = 0;
if (destin == src || src == 0)
return (destin);
while (src[i])
{
destin[i] = src[i];
i++;
}
destin[i] = 0;
return (destin);
}

/**
 * _strdup - duplicates a string
 * @dub_str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *dub_str)
{
int len = 0;
char *ret;
if (dub_str == NULL)
return (NULL);
while (*dub_str++)
len++;
ret = malloc(sizeof(char) * (len + 1));
if (!ret)
return (NULL);
for (len++; len--;)
ret[len] = *--dub_str;
return (ret);
}

/**
 * _puts - prints an input string
 * @strin: the string to be printed
 * Return: Nothing
 */
void _puts(char *strin)
{
int i = 0;
if (!strin)
return;
while (strin[i] != '\0')
{
_putchar(strin[i]);
i++;
}
}

/**
 * _putchar - writes the character c to stdout
 * @cha: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char cha)
{
static int i;
static char bufer[WRITE_BUF_SIZE];
if (cha == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, bufer, i);
i = 0;
}
if (cha != BUF_FLUSH)
bufer[i++] = cha;
return (1);
}
