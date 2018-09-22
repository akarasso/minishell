/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect_strcmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:59 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:45:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_redirect_strcmp(char *src, char *op, int *io_number)
{
	if (io_number)
		*io_number = (ft_isdigit(*src)) ? ft_atoi(src) : -1;
	while (ft_isdigit(*src))
		src++;
	return (ft_strncmp(src, op, ft_strlen(op)));
}
