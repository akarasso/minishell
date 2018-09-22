/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:07:43 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:07:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# define GNL_BUFF_SIZE 1

# include <unistd.h>
# include <dirent.h>

typedef struct	s_cbuffer
{
	int					fd;
	char				buff[GNL_BUFF_SIZE + 1];
	struct s_cbuffer	*next;
}				t_cbuffer;

int				get_next_line(const int fd, char **line);
int				ft_readdir(char *path, char ***res, int depth);

#endif
