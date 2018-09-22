/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:12:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:39:07 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

typedef struct s_shell	t_shell;

typedef struct			s_cmd
{
	t_dlst	*redir;
	t_shell	*shell;
	t_env	*env;
	int		saved_fd[3];
	char	**argv;
	char	*name;
	int		bg;
	int		argc;
}						t_cmd;

typedef struct			s_func
{
	char		*name;
	int			(*func)(t_cmd*);
}						t_func;

int						func_cmp(void *data, void *name);
t_func					*new_func(char *key, int (*func)(t_cmd*));
int						built_in_find(void *data, void *data2);
int						sh_cd(t_cmd *cmd);
int						sh_echo(t_cmd *cmd);
int						sh_env(t_cmd *cmd);
int						sh_exit(t_cmd *cmd);
int						sh_export(t_cmd *cmd);
int						sh_setenv(t_cmd *cmd);
int						sh_unset(t_cmd *cmd);
int						sh_unsetenv(t_cmd *cmd);
char					**sh_read_get_split_val(int flag);
int						sh_read(t_cmd *cmd);
t_btree					*init_shell_built_in(void);
void					tree_del(t_btree *tree);

#endif
