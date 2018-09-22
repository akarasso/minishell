/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:44:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:47:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_ast_split(t_ast_node *ast, int (*func)(void*))
{
	t_dlst_elem	*elem;

	if (!ast || !ast->token || !ast->token->next)
		return (0);
	elem = ast->token;
	while (elem)
	{
		if (func(elem->data))
			break ;
		elem = elem->next;
	}
	if (elem)
	{
		ft_ast_rsplit(ast, elem);
		return (1);
	}
	return (0);
}
