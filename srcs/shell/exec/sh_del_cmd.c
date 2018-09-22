/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_del_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:45:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_redir_del(t_dlst_elem *elem)
{
	t_redir *red;

	red = (t_redir*)elem->data;
	free(red->to);
	free(red);
}

void	sh_del_cmd(t_cmd **cmd)
{
	if (cmd && *cmd)
	{
		ft_dlst_del(&(*cmd)->redir, ft_redir_del);
		ft_strtab_del(&(*cmd)->argv);
		free(*cmd);
		*cmd = 0;
	}
}
