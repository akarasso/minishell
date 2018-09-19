#ifndef SHELL_H
# define SHELL_H

# define DEFAULT_HOME "/Users"

# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <pwd.h>

typedef struct s_shell t_shell;

# include "libft.h"
# include "shell_math.h"
# include "env.h"
# include "token.h"
# include "lexer.h"
# include "parser.h"
# include "ast.h"
# include "built_in.h"
# include "exec.h"
# include "dev.h"

# ifdef __linux__
#  define DEFAULT_HOME "/home"
# endif
# ifdef __mac__
#  define DEFAULT_HOME "/Users"
# endif

struct	s_shell
{
	t_dlst		*lexer;
	t_ast_node	*ast;
	t_btree		*func;
	t_env		*env;
	int			last_ret;
	char		**priv;
	char		*cmd;
};

/*
** Static Declaration
*/

extern char		*g_shell_op[7];
extern char		*g_shell_redirect[10];


int			expansion_get_tild_expansion(char **str, t_cmd *cmd, char *home);

/*
** IO
*/

void		sh_input(char *s);
void		sh_input_loop(t_shell *sh);

t_shell		*get_new_shell(char **env);

void		sh_expansion(t_cmd *cmd);
void		exp_backslash(char **tab);
void		exp_quote(char **tab);
int			exp_tilde(t_shell *shell, char **tab);
void		exp_vars(t_shell *shell, char **tab);
void		sh_expansion_vars_string(char **str, t_cmd *cmd);

#endif
