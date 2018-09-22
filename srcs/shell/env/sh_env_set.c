/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:44:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:48:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_env_set(char ***tabe, char *key, char *value, char flag)
{
	char	**env;
	char	*new;

	if (!key || !value)
		return (0);
	if (!(new = ft_3strjoinfree(key, "=", value, flag)))
		return (0);
	if ((env = sh_env_get_ref(*tabe, key)))
	{
		free(*env);
		*env = new;
	}
	else if (!ft_strtab_add(tabe, new))
	{
		free(new);
		return (0);
	}
	return (1);
}

int		sh_env_set_protected(t_env *env, char *key, char *value)
{
	char	**ref;

	if (!key || !value || sh_env_get(env->private, key))
	{
		ft_putstr("Minishell: read:'");
		ft_putstr(key);
		ft_putendl("' identifiant non valable");
		return (0);
	}
	else if ((ref = sh_env_get_ref(env->public, key)))
	{
		free(*ref);
		*ref = ft_3strjoinfree(key, "=", value, 0);
	}
	else
		sh_env_set(&env->local, key, value, 0);
	return (1);
}
