/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:37:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:37:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_unset(t_cmd *cmd)
{
	char	**argv;
	int		ret;

	if (cmd->argc < 2)
	{
		ft_putendl("Not enought args..");
		return (CMD_ERROR);
	}
	argv = &cmd->argv[1];
	ret = CMD_SUCCESS;
	while (*argv)
	{
		if (sh_env_get(cmd->shell->env->private, *argv))
		{
			ft_putendl("Read only variable");
			ret = CMD_ERROR;
		}
		else
		{
			sh_env_del(cmd->shell->env->public, *argv);
			sh_env_del(cmd->shell->env->local, *argv);
		}
		argv++;
	}
	return (ret);
}
