/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:42:24 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/01 15:19:05 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_env	*new_env(char *key, char *val)
{
	t_env	*new;
	char	*sep;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return (0);
	new->key = 0;
	new->val = 0;
	if (key && !(new->key = ft_strdup(key)))
	{
		free(new);
		return (0);
	}
	if (val && !(new->val = ft_strsplit(val, ':')))
	{
		free(new->key);
		free(new);
		return (0);
	}
	return (new);
}

void	add_env(t_env **lst, t_env *env)
{
	env->next = (*lst) ? *lst : 0;
	*lst = env;
}

t_env	*push_env(t_env **lst, char *env)
{
	t_env	*new;
	char	*sep;

	sep = ft_strchr(env, '=');
	if (!sep || !*sep)
		return (0);
	*sep = 0;
	if ((new = new_env(env, sep + 1)))
	{
		new->next = (*lst) ? *lst : 0;
		*lst = new;
	}
	return (new);
}

int		env_to_lst(t_mini *mini, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!push_env(&mini->env, env[i]))
			return (0);
		i++;
	}
	return (1);
}