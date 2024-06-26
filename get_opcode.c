#include "monty.h"
/**
 * get_opcode - exexutes monty opcode
 * @op: the opcode
 * Return: addres of function that exexutes op
 */
void (*get_opcode(char *op))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {

		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, op) == 0)
			break;
	}

	return (ops[i].f);
}
