/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:31:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/01 15:21:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_env	*get_env_value(t_mini *mini, char *key)
{
	t_env	*env;

	env = mini->env;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (0);
}

int		add_env_value(t_mini *mini, char *key, char *val)
{
	t_env	*env;

	if ((env = get_env_value(mini, key)))
	{
		free(env->val);
		env->val = ft_strsplit(val, ':');
	}
	else
	{
		if (!(env = new_env(key, val)))
			return (0);
		add_env(&mini->env, env);
	}
	return (1);
}

void	env_show(t_env *env)
{
	int i;

	while (env)
	{
		i = 0;
		if (env->key)
			write(1, env->key, ft_strlen(env->key));
		write(1, "=", 1);
		if (env->val)
		{
			while (env->val[i])
			{
				write(1, env->val[i], ft_strlen(env->val[i]));
				i++;
			}
		}
		write(1, "\n", 1);
		env = env->next;
	}
}