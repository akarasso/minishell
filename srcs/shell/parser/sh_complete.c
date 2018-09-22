/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:23 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:46:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		parser_check_quote(t_shell *sh)
{
	t_str_token	*tkn;
	char		quote;

	if (sh->lexer->last)
	{
		tkn = (t_str_token*)sh->lexer->last->data;
		if (tkn->type & (WORD | REDIRECT_PATH)
			&& (quote = quote_str_valid(tkn->value)))
		{
			ft_strdel(&sh->cmd);
			ft_putstr("quote>");
			get_next_line(0, &sh->cmd);
			sh->cmd = ft_3strjoinfree(tkn->value, "\n", sh->cmd, RIGHT);
			ft_dlst_delelem(sh->lexer, &sh->lexer->last, sh_token_del);
			sh_tokenize(sh);
			return (1);
		}
	}
	return (0);
}

int		parser_check_operator(t_shell *sh)
{
	int			ret;
	t_dlst_elem	*last;
	t_int_token	*tkn;

	last = sh->lexer->last;
	if (last && (ret = sh_tkn_is_operator((t_int_token*)last->data))
		&& (ret == 2 || ret == 3 || ret == 4))
	{
		tkn = (t_int_token*)last->data;
		ft_strdel(&sh->cmd);
		ft_putstr("operator>");
		get_next_line(0, &sh->cmd);
		sh->cmd = ft_strjoinfree(ft_itoa(tkn->value), sh->cmd, LEFT | RIGHT);
		sh_tokenize(sh);
		return (1);
	}
	return (0);
}
