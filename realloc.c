#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int j;
for (j = 0; j < n; j++)
s[j] = b;
return (s);
}

/**
 * ffree - frees a string of strings
 * @ppp: string of strings
 */
void ffree(char **ppp)
{
char **b = ppp;
if (!ppp)
return;
while (*ppp)
free(*ppp++);
free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @point: pointer to previous malloc'ated block
 * @oldsize: byte size of previous block
 * @newsize: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *point, unsigned int oldsize, unsigned int newsize)
{
char *b;
if (!point)
return (malloc(newsize));
if (!newsize)
return (free(point), NULL);
if (newsize == oldsize)
return (point);
b = malloc(newsize);
if (!b)
return (NULL);
oldsize = oldsize < newsize ? oldsize : newsize;
while (oldsize--)
b[oldsize] = ((char *)point)[oldsize];
free(point);
return (b);
}
