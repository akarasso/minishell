/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bin_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:53:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			is_valid(char *fullpath)
{
	int			rstat;
	int			raccess;
	struct stat	st;

	rstat = stat(fullpath, &st);
	raccess = access(fullpath, X_OK);
	if (rstat != -1 && raccess != -1 && !S_ISDIR(st.st_mode))
		return (CMD_SUCCESS);
	else if (rstat != -1 && raccess == -1)
		return (PERM);
	else if (rstat != -1 && S_ISDIR(st.st_mode))
		return (ISDIR);
	else if (rstat == -1)
		return (NOTEXIST);
	return (NOTEXIST);
}

char		**get_pathtab(t_shell *sh)
{
	char	**tab;
	char	*path_value;

	if (!(path_value = sh_env_get(sh->env->public, "PATH")))
		if (!(path_value = sh_env_get(sh->env->local, "PATH")))
			return (0);
	if (!(tab = ft_strsplit(path_value, ':')))
		return (0);
	return (tab);
}

char		*search_with_pathtab(char **pathtab, char *file, int *ret)
{
	char	*fullpath;

	fullpath = 0;
	*ret = CMD_ERROR;
	while (*pathtab)
	{
		fullpath = ft_3strjoinfree(*pathtab, "/", file, 0);
		if ((*ret = is_valid(fullpath)) == CMD_SUCCESS)
			break ;
		else
			ft_strdel(&fullpath);
		pathtab++;
	}
	return (fullpath);
}

static void	path_error(int *ret, char *file)
{
	if (*ret == NOTEXIST)
	{
		if (*file != '/' && *file != '.')
			ft_putendl("Command not found");
		else
			ft_putendl("No such file or directory");
		*ret = 127;
	}
	if (*ret == PERM || *ret == ISDIR)
	{
		if (*ret == PERM)
			ft_putendl("Permission denied");
		else
			ft_putendl("This is a directory");
		*ret = 126;
	}
}

char		*sh_bin_path(t_shell *sh, char *file, int *ret)
{
	char	**tab;
	char	*fullpath;

	fullpath = 0;
	*ret = CMD_ERROR;
	if ((tab = get_pathtab(sh)))
		fullpath = search_with_pathtab(tab, file, ret);
	if (*ret != CMD_SUCCESS)
	{
		if ((!ft_strncmp(file, "./", 2) || *file == '/')
			&& (*ret = is_valid(file)) == CMD_SUCCESS)
			fullpath = ((*file == '/') ? ft_strdup(file) : ft_strdup(file + 2));
		else
			*ret = NOTEXIST;
	}
	if (*ret != CMD_SUCCESS)
		path_error(ret, file);
	ft_strtab_del(&tab);
	return (*ret == CMD_SUCCESS) ? fullpath : 0;
}
