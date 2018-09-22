/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:41:28 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:41:29 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			exp_tilde(char **str, t_cmd *cmd, char *home)
{
	char		*tmp;

	(void)cmd;
	if (!home)
		return (0);
	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		tmp = *str;
		(*str) = ft_strjoinfree(home, &tmp[1], 0);
		free(tmp);
	}
	return (1);
}
