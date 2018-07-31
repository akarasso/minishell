/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:12:57 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/31 18:35:03 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;

	printf("%p\n", env);
	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr("$>");

		ft_strdel(&line);
	}
	return 0;
}