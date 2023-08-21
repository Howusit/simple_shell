#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @stri: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *stri)
{
int i = 0;
if (!stri)
return (0);
while (*stri++)
i++;
return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @stra1: the first strang
 * @stra2: the second strang
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *stra1, char *stra2)
{
while (*stra1 && *stra2)
{
if (*stra1 != *stra2)
return (*stra1 - *stra2);
stra1++;
stra2++;
}
if (*stra1 == *stra2)
return (0);
else
return (*stra1 < *stra2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haysta: string to search
 * @needle: the substring to find
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haysta, const char *needle)
{
while (*needle)
if (*needle++ != *haysta++)
return (NULL);
return ((char *)haysta);
}

/**
 * _strcat - concatenates two strings
 * @des: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *des, char *src)
{
char *ret = des;
while (*des)
des++;
while (*src)
*des++ = *src++;
*des = *src;
return (ret);
}
