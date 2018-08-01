/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:12:57 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/01 15:17:07 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_mini	*init()
{
	t_mini *mini;

	if (!(mini = (t_mini*)malloc(sizeof(t_mini))))
		return (0);
	mini->env = 0;
	return (mini);
}

int		main(int argc, char **argv, char **env)
{
	t_mini	*mini;
	char	*line;
	t_env	*e;
	int		i;

	if ((mini = init()))
	{
		env_to_lst(mini, env);
		e = get_env_value(mini, "PWD");
		add_env_value(mini, "test", "VALUUUUUUUE");
		add_env_value(mini, "test2", 0);
		env_show(mini->env);
	}
	return 0;
}