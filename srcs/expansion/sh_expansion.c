/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_get_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnebie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:49:03 by gnebie            #+#    #+#             */
/*   Updated: 2018/09/05 16:49:04 by gnebie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_home(t_shell *shell)
{
	struct passwd	*pwd;
	char			*home;
	char			*ptr;

	if ((home = sh_env_get(shell->env->public, "HOME")))
		return (ft_strdup(home));
	else
	{
		if ((ptr = sh_env_get(shell->env->private, "UID")))
		{
			if ((pwd = getpwuid(ft_atoi(ptr))))
				return (ft_strdup(pwd->pw_dir));
			else
				return (ft_strdup(DEFAULT_HOME));
		}
		else
			return (ft_strdup(DEFAULT_HOME));
	}
	return (0);
}

// void		*expansion_get_parameter_expansion(char **elem, t_cmd *cmd)
// {
// 	char	*last;
// 	char	*str;
// 	char	*res;
// ;
// 	str = *elem;
// 	if (!ft_strncmp(str, "${", 2) && *(last = ft_strlastchr(str)) == '}')
// 	{
// 		ft_strrmvchr(last);
// 		ft_strrmvchr(str);
// 		ft_strrmvchr(str);
// 		if ((res = exp_var(str, cmd->shell->env)))
// 		{
// 			free(str);
// 			*elem = res;
// 		}
// 	}
// 	return (NULL);
// }

void		*expansion_get_expansion_aritmetique(char **elem, t_cmd *cmd)
{
	char	*tmp;
	int		res;
	char	*str;

	(void)cmd;
	str = *elem;
	if (!ft_strncmp(str, "$((", 3) && !ft_strcmp_end(str, "))"))
	{
		ft_strrmvchr(ft_strlastchr(str));
		ft_strrmvchr(str);
		ft_strrmvchr(str);
		ft_strrmvchr(str);
		if (!math_eval(str, &res))
		{
			if (!(tmp = ft_itoa(res)))
				return (0);
			free(str);
			*elem = tmp;
		}
	}
	return (NULL);
}
/*
** $TRUC
** will be on the globing ?
*/

void		*expansion_get_pathname_expansion(char **elem, t_cmd *cmd)
{
	char	*str;
	char	*last;

	str = *elem;
	if (!ft_strncmp(str, "${", 2) && *(last = ft_strlastchr(str)) == '}')
	{
		ft_strrmvchr(last);
		ft_strrmvchr(str);
	}
	(void)elem;
	(void)cmd;
	return (NULL);
}

void		expansion_unquote(char **str)
{
	char	*endquote;
	char	*s;

	s = *str;
	while (*s)
	{
		if (*s == '\\')
			s++;
		else if (is_quote(*s))
		{
			endquote = s;
			goto_next_quote(&endquote);
			if (*endquote == *s)
			{
				ft_strrmvchr(endquote);
				ft_strrmvchr(s);
			}
			else
				s++;
		}
		s++;
	}
}

void		sh_expansion(t_cmd *cmd)
{
	char		**elem;
	char		*home;
	int			i;

	i = 0;
	home = get_home(cmd->shell);
	while (cmd->argv[i])
	{
		elem = &(cmd->argv[i]);
		exp_tilde(elem, cmd, home);
		exp_vars(elem, cmd);
		exp_arithmetic(elem);
		// expansion_get_expansion_aritmetique(elem, cmd);
		expansion_unquote(elem);
		i++;
	}
	free(home);
}
