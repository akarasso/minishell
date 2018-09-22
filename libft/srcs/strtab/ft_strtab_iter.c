/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:58:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtab_iter(char **tab, void (*func)(char *, void *), void *data)
{
	while (*tab)
	{
		func(*tab, data);
		tab++;
	}
}
