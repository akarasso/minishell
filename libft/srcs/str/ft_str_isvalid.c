/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:51:12 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:51:13 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_str_isvalid(char *str, char *token_chr)
{
	while (*str)
	{
		if (!ft_strchr(token_chr, *str))
			return (0);
		str++;
	}
	return (1);
}
