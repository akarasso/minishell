/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_substitute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:41:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:41:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*exp_sub_param(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)word;
	return (ft_strdup(val));
}

char	*exp_sub_word(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	return (ft_strdup(word));
}

char	*exp_sub_null(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	(void)word;
	return (ft_strdup(""));
}

char	*exp_sub_error(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)val;
	ft_putstr("expansion error substitute:: ");
	ft_putstr(key);
	ft_putstr(": ");
	ft_putendl(word);
	return (0);
}
