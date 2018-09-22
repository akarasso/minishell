/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:37:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:40:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	setenv_error(t_cmd *cmd)
{
	if (cmd->argc > 3)
	{
		ft_putendl("Too much args..");
		return (1);
	}
	if (cmd->argc < 2)
	{
		ft_putendl("Too few args..");
		return (1);
	}
	if (sh_env_get(cmd->shell->env->private, cmd->argv[1]))
	{
		ft_putendl("Read only variables");
		return (1);
	}
	if (!sh_env_validkey(cmd->argv[1]))
	{
		ft_putendl("Bad name");
		return (1);
	}
	return (0);
}

int			sh_setenv(t_cmd *cmd)
{
	if (setenv_error(cmd))
		return (CMD_ERROR);
	if (cmd->argc == 1)
		ft_strtab_print(cmd->shell->env->public);
	else
	{
		sh_env_del(cmd->shell->env->local, cmd->argv[1]);
		if (cmd->argv[2])
			sh_env_set(&cmd->shell->env->public, cmd->argv[1], cmd->argv[2], 0);
		else
			sh_env_set(&cmd->shell->env->public, cmd->argv[1], "", 0);
	}
	return (CMD_SUCCESS);
}
