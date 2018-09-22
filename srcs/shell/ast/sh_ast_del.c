/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:44:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:44:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_ast_del_elem(t_dlst_elem *elem)
{
	t_dlst_elem *tmp;
	t_str_token	*tkn;

	while (elem)
	{
		tmp = elem->next;
		tkn = elem->data;
		if (tkn->type & (OP | IO_NUMBER | REDIRECT))
			ft_del_chr_token((t_chr_token**)&tkn);
		else
			ft_del_str_token(&tkn);
		free(elem);
		elem = tmp;
	}
}

void	sh_ast_del(t_ast_node **ast)
{
	if (ast && *ast)
	{
		sh_ast_del_elem((*ast)->token);
		if ((*ast)->left)
			sh_ast_del(&(*ast)->left);
		if ((*ast)->right)
			sh_ast_del(&(*ast)->right);
		free(*ast);
		*ast = 0;
	}
}
