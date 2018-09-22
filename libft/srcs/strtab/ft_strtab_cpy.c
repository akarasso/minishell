/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:08 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strtab_cpy(char **src, char **dest)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
}
