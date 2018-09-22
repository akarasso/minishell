/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:46:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	check_operator(t_dlst_elem *elem, t_int_token *tkn)
{
	if (tkn->value == PIPE || tkn->value == OR || tkn->value == DAND)
	{
		if (!elem->prev || !elem->next)
			return (0);
		if (((t_int_token*)elem->prev->data)->type != WORD
			|| ((t_int_token*)elem->next->data)->type != WORD)
			return (0);
	}
	return (1);
}

static int	check_redirect(t_dlst_elem *elem)
{
	if (!elem->next)
		return (0);
	if (((t_int_token*)elem->next->data)->type != REDIRECT_PATH)
		return (0);
	return (1);
}

int			parser_syntax(t_shell *sh)
{
	t_dlst_elem *elem;
	t_int_token	*tkn;

	elem = sh->lexer->first;
	while (elem)
	{
		tkn = (t_int_token*)elem->data;
		if (tkn->type == OP && !check_operator(elem, tkn))
		{
			ft_putendl("Syntax error on operator token\n");
			return (0);
		}
		if (tkn->type == REDIRECT && !check_redirect(elem))
		{
			ft_putendl("Syntax error on redirect token\n");
			return (0);
		}
		elem = elem->next;
	}
	return (1);
}
