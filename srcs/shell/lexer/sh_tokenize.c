/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:18 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:46:18 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	get_token(char **cmd, t_shell *sh)
{
	int	ret;

	if ((ret = is_redirect(*cmd)) > -1)
		sh_newtkn_redirect(ret, cmd, sh);
	else if ((ret = ft_strtab_strncmp_i(g_shell_op, *cmd)) > -1)
		sh_newtkn_op(ret, cmd, sh);
	else if (is_word(*cmd))
		sh_newtkn_word(cmd, sh);
	else
		return (0);
	return (1);
}

void		sh_tokenize(t_shell *sh)
{
	char	*cmd;

	cmd = sh->cmd;
	if (!cmd)
		return ;
	while (*cmd)
	{
		if (!(get_token(&cmd, sh)))
			cmd++;
	}
}
