/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:08 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:53:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_newtkn_word(char **cmd, t_shell *sh)
{
	t_str_token	*tmp;
	t_str_token	*new;

	tmp = (sh->lexer->last) ? (t_str_token*)(sh->lexer->last->data) : 0;
	if (tmp && tmp->type == REDIRECT)
		new = ft_new_str_token(REDIRECT_PATH, cmd, goto_end_word);
	else
		new = ft_new_str_token(WORD, cmd, goto_end_word);
	if (!new)
		return ;
	ft_dlst_pushback(sh->lexer, new);
}

void	sh_newtkn_op(int value, char **cmd, t_shell *sh)
{
	t_int_token	*new;

	if (!(new = (t_int_token*)malloc(sizeof(*new))))
		return ;
	new->type = OP;
	new->value = value;
	(*cmd) += ft_strlen(g_shell_op[value]);
	ft_dlst_pushback(sh->lexer, new);
}

void	sh_newtkn_redirect(int index, char **cmd, t_shell *sh)
{
	t_int_token	*new;
	int			io_number;

	io_number = 0;
	sh_redirect_strcmp(*cmd, g_shell_redirect[index], &io_number);
	if (!(new = ft_new_int_token(IO_NUMBER, 0)))
		return ;
	new->value = io_number;
	ft_dlst_pushback(sh->lexer, new);
	if (!(new = ft_new_int_token(REDIRECT, 0)))
		return ;
	new->value = index;
	ft_dlst_pushback(sh->lexer, new);
	while (ft_isdigit(**cmd))
		(*cmd)++;
	(*cmd) += ft_strlen(g_shell_redirect[index]);
}
