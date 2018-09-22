/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:51:16 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:27 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_str.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
