/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:46:03 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:53:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_token_del(void *data)
{
	t_str_token *tkn;

	tkn = (t_str_token*)data;
	if (tkn->type & (OP | IO_NUMBER | REDIRECT))
		ft_del_chr_token((t_chr_token**)&data);
	else
		ft_del_str_token((t_str_token**)&data);
}
