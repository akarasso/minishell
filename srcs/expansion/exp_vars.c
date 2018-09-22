/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:41:32 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:43:44 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*exp_vars_pos(char *str)
{
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '\'')
			goto_next_quote(&str);
		else if (*str == '$' && (ft_isalpha(*(str + 1))
			|| *(str + 1) == '?' || *(str + 1) == '{'))
			return (str);
		if (*str)
			str++;
	}
	return (0);
}

static void		goto_end_parent(char **s)
{
	int stack;

	stack = 0;
	while (**s)
	{
		if (**s == '{')
			stack++;
		if (**s == '}')
			stack--;
		(*s)++;
		if (!stack)
			break ;
	}
}

static char		*exp_get_key(char *s)
{
	char *end;

	end = s;
	if (*s == '{')
		goto_end_parent(&end);
	else
	{
		if (ft_isdigit(*end) || *end == '?' || *end == '@' || *end == '*'
			|| *end == '#' || *end == '$' || *end == '-')
			return (ft_strsub(s, 0, end - s + 1));
		while (*end && (ft_isalpha(*end) || ft_isdigit(*end) || *end == '_'))
			end++;
	}
	return (ft_strsub(s, 0, end - s));
}

int				exp_vars_exec(char *pos, int *i, char **str, t_cmd *cmd)
{
	int		ret;
	int		lkey;
	char	*val;
	char	*key;

	ret = 0;
	*pos = 0;
	if ((key = exp_get_key(&(*str)[*i])))
	{
		lkey = ft_strlen(key);
		if ((val = exp_get_var(key, cmd->shell->env)))
		{
			(*str) = ft_3strjoinfree((*str), val, &(*str)[*i + lkey], LEFT);
			ret = ft_strlen(val) - 1;
			ft_strdel(&val);
		}
		ft_strdel(&key);
	}
	return (ret);
}

void			exp_vars(char **str, t_cmd *cmd)
{
	char	*start;
	char	*pos;
	int		i;

	start = *str;
	i = 0;
	while ((pos = exp_vars_pos(&start[i])))
	{
		i = pos - start + 1;
		i += exp_vars_exec(pos, &i, &start, cmd);
	}
	*str = start;
}
