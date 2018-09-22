/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_onlychr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:51:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:51:17 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_str_onlychr(char *str, char *valid)
{
	while (*str)
	{
		if (!ft_strchr(valid, *str))
			return (0);
		str++;
	}
	return (1);
}
