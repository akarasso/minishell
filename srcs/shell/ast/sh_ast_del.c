#include "shell.h"

void	sh_ast_del(t_ast_node **ast)
{
	t_ast_node	*left;
	t_ast_node	*right;

	if (ast && *ast)
	{
		left = (*ast)->left;
		right = (*ast)->right;
		if (left)
			sh_ast_del(&left);
		if (right)
			sh_ast_del(&right);
		free(*ast);
		*ast = 0;
	}
}
