/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:48 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:45:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_redirect(char *str)
{
	int i;
	int last;

	i = 0;
	last = -1;
	while (g_shell_redirect[i])
	{
		if (!sh_redirect_strcmp(str, g_shell_redirect[i], 0))
			last = i;
		i++;
	}
	return (last);
}
