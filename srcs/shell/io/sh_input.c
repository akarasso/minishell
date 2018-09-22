/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:36 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:07:54 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	prompt(t_shell *sh)
{
	char *cwd;
	char *home;

	home = env_get_first(sh->env, "HOME");
	if ((cwd = env_get_first(sh->env, "PWD")))
	{
		if (home && !ft_strcmp(home, cwd))
		{
			(sh->last_ret) ? ft_putstr(RED) : ft_putstr(GREEN);
			ft_putstr("~"RESET);
		}
		else
		{
			(sh->last_ret) ? ft_putstr(RED) : ft_putstr(GREEN);
			ft_putstr(cwd);
			ft_putstr(RESET);
		}
	}
	else
		ft_putstr("?????");
	ft_putstr(" $>");
}

void		sh_input_loop(t_shell *sh)
{
	sh->cmd = 0;
	while (!sh->force_exit)
	{
		prompt(sh);
		get_next_line(0, &sh->cmd);
		sh_tokenize(sh);
		if (sh_parser(sh))
		{
			sh_ast_construct(sh);
			sh_exec(sh, sh->ast);
			sh_ast_del(&sh->ast);
			sh->lexer->first = 0;
			sh->lexer->last = 0;
			sh->lexer->len = 0;
		}
		else
			ft_dlst_clr(sh->lexer, sh_token_del);
		ft_strdel(&sh->cmd);
	}
}
