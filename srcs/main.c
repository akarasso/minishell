/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 01:52:27 by hoax              #+#    #+#             */
/*   Updated: 2018/09/22 11:42:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_shell			*get_new_shell(char **env)
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
		ft_dlst_del(&sh->lexer, 0);
		tree_del(sh->func);
		free(sh);
		return (0);
	}
	return (sh);
}

void			del_shell(t_shell *sh)
{
	if (sh)
	{
		tree_del(sh->func);
		ft_dlst_del(&sh->lexer, 0);
		sh_env_destroy(sh->env);
		free(sh);
	}
}

int				main(int argc, char **argv, char **env)
{
	int		last_ret;
	t_shell *sh;

	(void)argc;
	(void)argv;
	if ((sh = get_new_shell(env)))
	{
		if (!env_get_first(sh->env, "PWD"))
			sh_env_set(&sh->env->public, "PWD", getcwd(NULL, 0), RIGHT);
		sh_input_loop(sh);
	}
	last_ret = sh->last_ret;
	del_shell(sh);
	return (last_ret);
}
