/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:12:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:28:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define OP 0x01
# define WORD 0x02
# define REDIRECT 0x04
# define IO_NUMBER 0x08
# define REDIRECT_PATH 0x10

# define OP_PAT_LST 0x20
# define PAT_LST 0x40
# define META 0x80
# define RANGE 0x100
# define FILTER 0x200
# define CST 0x400
# define SUB_DIR 0x800

# define SEMI 0
# define AND 1
# define PIPE 2
# define OR 3
# define DAND 4
# define DSEMI 5

# define LESS 0
# define GREAT 1
# define DLESS 2
# define DGREAT 3
# define LESSAND 4
# define GREATAND 5
# define LESSGREAT 6
# define DLESST 7
# define GREATPIPE 8

/*
** Globbing Lexer Token definition
*/

typedef struct	s_rng_token
{
	int		type;
	char	*value;
	char	allow[256];
	char	negative;
}				t_rng_token;

typedef struct	s_strtab_token
{
	int		type;
	char	*value;
	char	**tab;
}				t_strtab_token;

#endif
