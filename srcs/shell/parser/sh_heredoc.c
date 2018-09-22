/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:31 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:02:26 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	get_heredoc_concat(char *value, char *line, char *key)
{
	int ret;

	ret = 1;
	if (ft_strcmp(line, key))
	{
		if (!value)
			ft_strdup(line);
		else
			ft_3strjoinfree(value, "\n", line, LEFT);
	}
	else
	{
		value = ft_strjoinfree(value, "\n", LEFT);
		ret = 0;
	}
	return (ret);
}

static int	get_heredoc_value(t_dlst_elem *elem)
{
	char	*key;
	char	*line;
	char	*value;

	key = ((t_str_token*)elem->data)->value;
	line = 0;
	value = 0;
	while (1)
	{
		ft_putstr("heredoc>");
		get_next_line(0, &line);
		if (!get_heredoc_concat(value, line, key))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&key);
	ft_strdel(&line);
	((t_str_token*)elem->data)->value = value;
	return (1);
}

int			sh_heredoc(t_shell *sh)
{
	t_dlst_elem *elem;
	t_int_token	*tkn;

	elem = sh->lexer->first;
	while (elem)
	{
		tkn = (t_int_token*)elem->data;
		if (tkn->type == REDIRECT && tkn->value == DLESS)
		{
			if (!elem->next
				|| ((t_str_token*)elem->next->data)->type != REDIRECT_PATH)
				return (0);
			get_heredoc_value(elem->next);
		}
		elem = elem->next;
	}
	return (1);
}
