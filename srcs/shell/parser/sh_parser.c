/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:49 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:03:01 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_parser(t_shell *sh)
{
	while (parser_check_quote(sh) || parser_check_operator(sh))
	{
		;
	}
	if (!parser_syntax(sh))
		return (0);
	if (!sh_heredoc(sh))
		return (0);
	return (1);
}
