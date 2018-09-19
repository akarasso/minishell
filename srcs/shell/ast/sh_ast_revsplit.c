#include "shell.h"

int		sh_ast_revsplit(t_ast_node *ast, int(*func)(void*))
{
	t_dlst_elem	*split;
	t_dlst_elem	*elem;

	if (!ast || !ast->token || !ast->token || !ast->token->next)
		return (0);
	elem = ast->token;
	split = 0;
	while (elem)
	{
		if (func(elem->data))
			split = elem;
		elem = elem->next;
	}
	if (split)
	{
		ft_ast_rsplit(ast, split);
		return (1);
	}
	return (0);
}
