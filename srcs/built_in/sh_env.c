/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:37:03 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:38:02 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	remove_env(char ***argv, t_shell *new)
{
	char	**ptr;
	int		flag;

	ptr = *argv;
	flag = 0;
	while (*ptr && (!ft_strcmp(*ptr, "-u") || !ft_strcmp(*ptr, "--unset")
		|| !ft_strcmp(*ptr, "-i")))
	{
		if (*ptr && !ft_strcmp(*ptr, "-i"))
		{
			flag = 1;
			ptr++;
		}
		else if (*(++ptr))
			sh_env_del(new->env->public, *ptr++);
	}
	if (flag)
	{
		ft_strtab_del(&new->env->public);
		new->env->public = ft_strtab_new(0);
	}
	*argv = ptr;
}

static void	modify_env(char ***argv, t_shell *new)
{
	char	**ptr;
	char	*pos;

	ptr = *argv;
	while (*ptr && (pos = ft_strchr(*ptr, '=')))
	{
		*pos = 0;
		sh_env_set(&new->env->public, *ptr, pos + 1, 0);
		ptr++;
	}
	*argv = ptr;
}

static int	exec_built_in(char *line, t_shell *shell)
{
	int ret;

	shell->cmd = line;
	sh_tokenize(shell);
	ret = CMD_ERROR;
	if (sh_parser(shell))
	{
		sh_ast_construct(shell);
		ret = sh_exec(shell, shell->ast);
		sh_ast_del(&shell->ast);
		shell->lexer->first = 0;
		shell->lexer->last = 0;
		shell->lexer->len = 0;
	}
	else
		ft_dlst_clr(shell->lexer, sh_token_del);
	ft_strdel(&line);
	del_shell(shell);
	return (ret);
}

int			sh_env(t_cmd *cmd)
{
	t_shell	*new;
	char	*line;
	char	**argv;

	if (!(new = get_new_shell(cmd->shell->env->public)))
		return (CMD_ERROR);
	argv = &cmd->argv[1];
	remove_env(&argv, new);
	modify_env(&argv, new);
	if (!*argv)
	{
		ft_strtab_print(new->env->public);
		del_shell(new);
	}
	else
	{
		line = 0;
		while (*argv)
		{
			line = ft_3strjoinfree(line, " ", *argv, LEFT);
			argv++;
		}
		return (exec_built_in(line, new));
	}
	return (CMD_SUCCESS);
}
