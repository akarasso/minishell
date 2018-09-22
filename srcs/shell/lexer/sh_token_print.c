/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:55:13 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	print_key(int type)
{
	if (type == WORD)
		ft_putstr("WORD\t\t");
	else if (type == OP)
		ft_putstr("OP\t\t");
	else if (type == IO_NUMBER)
		ft_putstr("IO_NUMBER\t");
	else if (type == REDIRECT)
		ft_putstr("REDIRECT\t");
	else if (type == REDIRECT_PATH)
		ft_putstr("TO\t\t");
	else
		ft_putstr("\t\t");
}

void		sh_token_print(void *data)
{
	t_str_token	*tkn;

	if (!data)
		return ;
	tkn = (t_str_token*)data;
	ft_putstr(RED"Token:\t"RESET);
	print_key(tkn->type);
	if (tkn->type == OP)
		ft_putendl(g_shell_op[((t_int_token*)tkn)->value]);
	else if (tkn->type == REDIRECT)
		ft_putendl(g_shell_redirect[((t_int_token*)tkn)->value]);
	else if (tkn->type == IO_NUMBER)
	{
		ft_putnbr(((t_int_token*)tkn)->value);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr(BBLUE);
		ft_putendl(tkn->value);
		ft_putstr(RESET);
	}
}

void		sh_lexer_print(t_shell *sh)
{
	ft_putendl(BBLUE"__________DEBUG LEXER__________"RESET);
	ft_putstr("Nombre de token: "RED);
	ft_putnbr(sh->lexer->len);
	ft_putendl(RESET);
	ft_dlst_iter_data(sh->lexer, sh_token_print);
	ft_putendl(BBLUE"________________________________"RESET);
}
