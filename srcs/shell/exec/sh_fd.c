/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:23 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:45:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_std_save(int tab[3])
{
	tab[0] = dup(STDIN);
	tab[1] = dup(STDOUT);
	tab[2] = dup(ERROUT);
}

void	sh_std_restore(int tab[3])
{
	dup2(tab[0], STDIN);
	dup2(tab[1], STDOUT);
	dup2(tab[2], ERROUT);
	close(tab[0]);
	close(tab[1]);
	close(tab[2]);
}
