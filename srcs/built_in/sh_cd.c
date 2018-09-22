/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:36:54 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:33:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_set_pwd(t_cmd *cmd, char *path)
{
	int		ret;
	char	*crtpwd;

	ret = CMD_SUCCESS;
	if (chdir(path))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		ret = CMD_ERROR;
	}
	if ((crtpwd = sh_env_get(cmd->shell->env->public, "PWD")))
		sh_env_set(&cmd->shell->env->public, "OLDPWD", crtpwd, 0);
	sh_env_set(&cmd->shell->env->public, "PWD", getcwd(NULL, 0), RIGHT);
	return (ret);
}

int			sh_cd(t_cmd *cmd)
{
	char	*newdir;
	int		ret;

	ret = CMD_SUCCESS;
	if (cmd->argc > 3)
	{
		ft_putendl("Too many args..");
		return (CMD_ERROR);
	}
	if (cmd->argc == 1)
		newdir = ft_strdup(sh_env_get(cmd->shell->env->public, "HOME"));
	else if (!ft_strcmp(cmd->argv[1], "-"))
		newdir = ft_strdup(sh_env_get(cmd->shell->env->public, "OLDPWD"));
	else
		newdir = ft_strdup(cmd->argv[1]);
	if (newdir)
		ret = sh_set_pwd(cmd, newdir);
	ft_strdel(&newdir);
	return (ret);
}
