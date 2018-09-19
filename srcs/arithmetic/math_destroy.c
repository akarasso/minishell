#include "shell.h"

void 	math_destroy_ast(t_ast_node *node)
{
	t_str_token	*tkn;

	if (node)
	{
		if (node->left)
			math_destroy_ast(node->left);
		if (node->right)
			math_destroy_ast(node->right);
		if (node->token)
		{
			tkn = node->token->data;
			if (tkn)
			{
				if (tkn->type == MATH_PARENTHESE)
					free(tkn->value);
				free(tkn);
			}
			free(node->token);
		}
		free(node);
	}
}

void	math_destroy_tkn(t_dlst_elem *elem)
{
	t_str_token *tkn;

	tkn = elem->data;
	printf("CALL\n");
	if (tkn)
	{
		if (tkn->type == MATH_PARENTHESE)
			free(tkn->value);
		free(tkn);
	}
}

void 	math_destroy(t_meval *ptr)
{
	if (ptr)
	{
		if (ptr->ast)
		{
			math_destroy_ast(ptr->ast);
			free(ptr->lexer);
		}
		else
		{
			ft_dlst_del(&ptr->lexer, math_destroy_tkn);
		}
		free(ptr);
	}
}
