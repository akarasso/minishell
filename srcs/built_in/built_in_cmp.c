/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:36:45 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:04:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		func_cmp(void *data, void *data2)
{
	return (ft_strcmp(((t_func*)data)->name, ((t_func*)data2)->name));
}

int		built_in_find(void *data, void *data2)
{
	return (ft_strcmp(((t_func*)data)->name, (char*)data2));
}
