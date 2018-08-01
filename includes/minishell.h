/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:25:35 by akarasso          #+#    #+#             */
/*   Updated: 2018/08/01 15:21:21 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	struct s_env	*next;
	char			*key;
	char			**val;
}				t_env;

typedef struct	s_mini
{
	t_env			*env;
}				t_mini;

int			parse(char *line);
int			env_to_lst(t_mini *mini, char **env);
t_env		*get_env_value(t_mini *mini, char *key);
void		env_show(t_env *env);
void		add_env(t_env **lst, t_env *env);
t_env		*new_env(char *key, char *val);
int			add_env_value(t_mini *mini, char *key, char *val);
void		add_env(t_env **lst, t_env *env);

#endif