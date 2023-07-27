#include "monty.h"

/**
 * comment_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool comment_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool argument_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - check if push opcode is being used and validates the argument
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @meta: struct containing all allocated memory
 *
 * Return: 0 on success, -1 on failure
 */
int push_check(line_t line, meta_t *meta, char *opcode)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!argument_check(line.content[1]))
		{
			free_stack(&(meta->stack));
			return (-1);
		}

		int arg_value = atoi(line.content[1]);
	}

	return (0);
}
