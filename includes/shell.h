/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:12:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 12:18:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define STDIN 0
# define STDOUT 1
# define ERROUT 2
# define ISDIR -1
# define PERM -2
# define NOTFOUND -3
# define NOTEXIST -4
# define CMD_SUCCESS 0
# define CMD_ERROR 1
# ifdef __linux__
#  define DEFAULT_HOME "/home"
# endif
# ifdef __APPLE__
#  define DEFAULT_HOME "/Users"
# endif

# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <pwd.h>
# include "libft.h"
# include "shell_math.h"
# include "env.h"
# include "token.h"
# include "lexer.h"
# include "built_in.h"

typedef struct s_shell		t_shell;

typedef struct				s_redir
{
	char	*to;
	int		type;
	int		io_number;
}							t_redir;

typedef struct s_varsexp	t_varsexp;

typedef struct				s_varsexp_rules
{
	char		*op;
	char		*(*set)(t_varsexp *exp, char *key, char *val, char *word);
	char		*(*null)(t_varsexp *exp, char *key, char *val, char *word);
	char		*(*unset)(t_varsexp *exp, char *key, char *val, char *word);
}							t_varsexp_rules;

struct						s_varsexp
{
	t_env			*env;
	char			*str;
	char			*res;
	t_varsexp_rules	*rule;
	char			format;
};

struct						s_shell
{
	t_dlst		*lexer;
	t_ast_node	*ast;
	t_btree		*func;
	t_env		*env;
	int			last_ret;
	int			force_exit;
	char		**priv;
	char		*cmd;
};

/*
** Static Declaration
*/

extern char					*g_shell_op[7];
extern char					*g_shell_redirect[10];

/*
** Ast
*/

void						sh_ast_construct(t_shell *sh);
int							sh_ast_revsplit(t_ast_node *ast, int (*f)(void*));
int							sh_ast_split(t_ast_node *ast, int(*func)(void*));
void						sh_ast_del(t_ast_node **ast);

/*
** Exec
*/

int							sh_exec(t_shell *sh, t_ast_node *node);
int							sh_exec_cmd(t_shell *sh, t_ast_node *ast);
void						sh_std_save(int tab[3]);
void						sh_std_restore(int tab[3]);
t_cmd						*sh_new_cmd(t_shell *sh, t_dlst_elem *token);
void						sh_del_cmd(t_cmd **cmd);
char						*sh_bin_path(t_shell *sh, char *file, int *ret);
int							sh_build_redir(t_ast_node *ast, t_cmd *cmd);
int							sh_exec_pipedcmd(t_shell *sh, t_ast_node *ast);

/*
** Expansion
*/

void						sh_expansion(t_cmd *cmd);
int							exp_tilde(char **str, t_cmd *cmd, char *home);
void						exp_vars(char **str, t_cmd *cmd);
char						*exp_get_var(char *str, t_env *env);
void						exp_arithmetic(char **str);

void						exp_backslash(char **tab);
void						exp_quote(char **tab);
void						sh_expansion_vars_string(char **str, t_cmd *cmd);

char						*sh_expansion_var(char *str, t_env *env);
char						*exp_sub_param(t_varsexp *exp,
					char *key, char *val, char *word);
char						*exp_sub_word(t_varsexp *exp,
					char *key, char *val, char *word);
char						*exp_sub_null(t_varsexp *exp,
					char *key, char *val, char *word);
char						*exp_sub_error(t_varsexp *exp,
					char *key, char *val, char *word);
char						*exp_assign(t_varsexp *exp,
					char *key, char *val, char *word);
char						*exp_unhandle(t_varsexp *exp,
					char *key, char *val, char *word);

/*
** IO
*/

void						sh_input(char *s);
void						sh_input_loop(t_shell *sh);

t_shell						*get_new_shell(char **env);
void						del_shell(t_shell *sh);

#endif
