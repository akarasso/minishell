#include "shell.h"

static int	is_op_prio(void *data)
{
	t_int_token	*tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == MATH_OPERATOR
		&& (tkn->value == '*' || tkn->value == '/'))
		return (1);
	return (0);
}

static int	is_op(void *data)
{
	t_int_token	*tkn;

	tkn = (t_int_token*)data;
	if (tkn && tkn->type == MATH_OPERATOR
		&& (tkn->value == '-' || tkn->value == '+'))
		return (1);
	return (0);
}

t_ast_node	*math_ast(t_dlst *lexer)
{
	t_ast_node *ast;

	ast = ft_ast_new(lexer->first);
	math_ast_split_tree(ast, is_op);
	math_ast_split_tree(ast, is_op_prio);
	return (ast);
}
// echo $(10+1*2)
