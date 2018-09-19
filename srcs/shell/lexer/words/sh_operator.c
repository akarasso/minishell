#include "shell.h"

int		is_terminator(void *data)
{
	t_int_token *tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == OP && tkn->value == SEMI)
		return (1);
	return (0);
}

int		is_logical(void *data)
{
	t_int_token *tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == OP && (tkn->value == DAND || tkn->value == OR))
		return (tkn->value);
	return (0);
}

int		is_pipe(void *data)
{
	t_int_token *tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == OP && tkn->value == PIPE)
		return (1);
	return (0);
}

int		sh_tkn_is_operator(void *data)
{
	t_int_token	*tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == OP)
		return (tkn->value);
	return (0);
}
