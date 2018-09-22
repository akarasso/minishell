/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ast_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:13:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:14:11 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		math_ast_split(t_ast_node *ast, int (*func)(void*))
{
	t_dlst_elem	*elem;

	if (!ast || !ast->token || !ast->token->next)
		return (0);
	elem = ast->token;
	while (elem)
	{
		if (func(elem->data))
			break ;
		elem = elem->next;
	}
	if (elem)
	{
		ft_ast_rsplit(ast, elem);
		return (1);
	}
	return (0);
}

void	math_ast_split_tree(t_ast_node *ast, int (*func)(void *data))
{
	math_ast_split(ast, func);
	if (ast && ast->right)
		math_ast_split_tree(ast->right, func);
	if (ast && ast->left)
		math_ast_split_tree(ast->left, func);
}
