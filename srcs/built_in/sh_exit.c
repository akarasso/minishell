/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:37:08 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:38:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_exit_error(t_cmd *cmd)
{
	if (cmd->argc > 2)
	{
		ft_putendl("Too many..");
		return (1);
	}
	if (cmd->argv[1] && !ft_strdigit(cmd->argv[1]))
	{
		ft_putendl("Only num char..");
		return (1);
	}
	return (0);
}

int			sh_exit(t_cmd *cmd)
{
	char	*str;
	int		ret;

	if (sh_exit_error(cmd))
		return (CMD_ERROR);
	str = (cmd->argv[1]) ? cmd->argv[1]
			: sh_env_get(cmd->shell->env->private, "?");
	if (!str)
		return (CMD_ERROR);
	ret = ft_atoi(str);
	cmd->shell->force_exit = 1;
	return (ret);
}
