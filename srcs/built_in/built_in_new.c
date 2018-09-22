/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:36:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:38:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_btree		*init_shell_built_in(void)
{
	t_btree	*tree;

	tree = 0;
	if (!ft_btree_push(&tree, func_cmp, new_func("echo", sh_echo))
		|| !ft_btree_push(&tree, func_cmp, new_func("cd", sh_cd))
		|| !ft_btree_push(&tree, func_cmp, new_func("env", sh_env))
		|| !ft_btree_push(&tree, func_cmp, new_func("exit", sh_exit))
		|| !ft_btree_push(&tree, func_cmp, new_func("export", sh_export))
		|| !ft_btree_push(&tree, func_cmp, new_func("setenv", sh_setenv))
		|| !ft_btree_push(&tree, func_cmp, new_func("unset", sh_unset))
		|| !ft_btree_push(&tree, func_cmp, new_func("read", sh_read))
		|| !ft_btree_push(&tree, func_cmp, new_func("unsetenv", sh_unsetenv)))
		return (0);
	return (tree);
}

void		tree_del(t_btree *tree)
{
	if (tree)
	{
		if (tree->data)
		{
			free(((t_func*)tree->data)->name);
			free(tree->data);
		}
		if (tree->left)
			tree_del(tree->left);
		if (tree->right)
			tree_del(tree->right);
		free(tree);
	}
}

t_func		*new_func(char *key, int (*func)(t_cmd*))
{
	t_func	*new;

	if (!(new = (t_func*)malloc(sizeof(*new))))
		return (0);
	if (!(new->name = ft_strdup(key)))
	{
		free(new);
		return (0);
	}
	new->func = func;
	return (new);
}
