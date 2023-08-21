#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @data: the parameter struct
 * @bufr: the char buffer
 * @p: address of current position in buf
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *data, char *bufr, size_t *p)
{
size_t j = *p;
if (bufr[j] == '|' && bufr[j + 1] == '|')
{
bufr[j] = 0;
j++;
data->cmd_buf_type = CMD_OR;
}
else if (bufr[j] == '&' && bufr[j + 1] == '&')
{
bufr[j] = 0;
j++;
data->cmd_buf_type = CMD_AND;
}
else if (bufr[j] == ';')
{
bufr[j] = 0;
data->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = j;
return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @data: the parameter struct
 * @bufr: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @leng: length of buf
 * Return: Void
 */
void check_chain(info_t *data, char *bufr, size_t *p, size_t i, size_t leng)
{
size_t j = *p;
if (data->cmd_buf_type == CMD_AND)
{
if (data->status)
{
bufr[i] = 0;
j = leng;
}
}
if (data->cmd_buf_type == CMD_OR)
{
if (!data->status)
{
bufr[i] = 0;
j = leng;
}
}
*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @data: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *data)
{
int c;
list_t *node;
char *p;
for (c = 0; c < 10; c++)
{
node = node_starts_with(data->alias, data->argv[0], '=');
if (!node)
return (0);
free(data->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
data->argv[0] = p;
}
return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @data: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *data)
{
int c = 0;
list_t *node;
for (c = 0; data->argv[c]; c++)
{
if (data->argv[c][0] != '$' || !data->argv[c][1])
continue;
if (!_strcmp(data->argv[c], "$?"))
{
replace_string(&(data->argv[c]),
_strdup(convert_number(data->status, 10, 0)));
continue;
}
if (!_strcmp(data->argv[c], "$$"))
{
replace_string(&(data->argv[c]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(data->env, &data->argv[c][1], '=');
if (node)
{
replace_string(&(data->argv[c]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&data->argv[c], _strdup(""));
}
return (0);
}

/**
 * replace_string - replaces string
 * @oldstr: address of old string
 * @newstr: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **oldstr, char *newstr)
{
free(*oldstr);
*oldstr = newstr;
return (1);
}
