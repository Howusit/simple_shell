#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info;
if (!path || stat(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dup_chars - duplicates characters
 * @path_str: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *path_str, int start, int stop)
{
static char bufer[1024];
int i = 0, j = 0;
for (j = 0, i = start; i < stop; i++)
if (path_str[i] != ':')
bufer[j++] = path_str[i];
bufer[j] = 0;
return (bufer);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @path_str: the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *path_str, char *cmd)
{
int j = 0, curr_pos = 0;
char *dir;
if (!path_str)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!path_str[j] || path_str[j] == ':')
{
dir = dup_chars(path_str, curr_pos, j);
if (!*dir)
_strcat(dir, cmd);
else
{
_strcat(dir, "/");
_strcat(dir, cmd);
}
if (is_cmd(info, dir))
return (dir);
if (!path_str[j])
break;
curr_pos = j;
}
j++;
}
return (NULL);
}
