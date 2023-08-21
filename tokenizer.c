#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @intstr: the input string
 * @deli: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *intstr, char *deli)
{
int i, j, k, m, numwords = 0;
char **s;
if (intstr == NULL || intstr[0] == 0)
return (NULL);
if (!deli)
deli = " ";
for (i = 0; intstr[i] != '\0'; i++)
if (!is_delim(intstr[i], deli)
&& (is_delim(intstr[i + 1], deli) || !intstr[i + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(intstr[i], deli))
i++;
k = 0;
while (!is_delim(intstr[i + k], deli) && intstr[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = intstr[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
 * **strtow2 - splits a string into words
 * @strin: the input string
 * @del: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *strin, char del)
{
int i, j, k, m, numofwords = 0;
char **s;
if (strin == NULL || strin[0] == 0)
return (NULL);
for (i = 0; strin[i] != '\0'; i++)
if ((strin[i] != del && strin[i + 1] == del) ||
(strin[i] != del && !strin[i + 1]) || strin[i + 1] == del)
numofwords++;
if (numofwords == 0)
return (NULL);
s = malloc((1 + numofwords)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numofwords; j++)
{
while (strin[i] == del && strin[i] != del)
i++;
k = 0;
while (strin[i + k] != del && strin[i + k] && strin[i + k] != del)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = strin[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}
