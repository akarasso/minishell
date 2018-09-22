/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 01:52:27 by hoax              #+#    #+#             */
/*   Updated: 2018/09/05 14:13:26 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		tree_del(t_btree *tree)
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

static t_btree	*init_shell_built_in()
{
	t_btree	*tree;

	tree = 0;
	if (!ft_btree_push(&tree, built_in_cmp, built_in_new("echo", sh_echo))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("cd", sh_cd))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("env", sh_env))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("exit", sh_exit))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("export", sh_export))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("setenv", sh_setenv))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("unset", sh_unset))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("read", sh_read))
		|| !ft_btree_push(&tree, built_in_cmp, built_in_new("unsetenv", sh_unsetenv)))
		return (0);
	return (tree);
}

t_shell		*get_new_shell(char **env)
{
	t_shell *sh;

	if (!(sh = (t_shell*)ft_memalloc(sizeof(*sh))))
		return (0);
	if (!(sh->lexer = ft_dlst_new(0)))
	{
		free(sh);
		return (0);
	}
	if (!(sh->func = init_shell_built_in()))
	{
		ft_dlst_del(&sh->lexer, 0);
		free(sh);
		return (0);
	}
	if (!(sh->env = sh_env_init(env)))
	{
		tree_del(sh->func);
		ft_dlst_del(&sh->lexer, 0);
		free(sh);
		return (0);
	}
	return (sh);
}

void	del_shell(t_shell *sh)
{
	if (sh)
	{
		tree_del(sh->func);
		ft_dlst_del(&sh->lexer, 0);
		sh_env_destroy(sh->env);
		free(sh);
	}
}

int			main(int argc, char **argv, char **env)
{
	t_shell *sh;

	(void)argc;
	(void)argv;
	if ((sh = get_new_shell(env)))
		sh_input_loop(sh);
	del_shell(sh);
	return (0);
}
