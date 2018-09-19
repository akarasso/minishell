#ifndef EXEC_H
# define EXEC_H

# define STDIN 0
# define STDOUT 1
# define ERROUT 2

# define ISDIR -1
# define PERM -2
# define NOTFOUND -3
# define NOTEXIST -4

# define CMD_SUCCESS 0
# define CMD_ERROR 1

typedef struct	s_redir
{
	char	*to;
	int		type;
	int		io_number;
}				t_redir;

int		sh_exec(t_shell *sh, t_ast_node *node);
int		sh_exec_cmd(t_shell *sh, t_ast_node *ast);
void	sh_std_save(int tab[3]);
void	sh_std_restore(int tab[3]);
t_cmd	*sh_new_cmd(t_shell *sh, t_dlst_elem *token);
void	sh_del_cmd(t_cmd **cmd);
char	*sh_bin_path(t_shell *sh, char *file, int *ret);
int		sh_build_redir(t_ast_node *ast, t_cmd *cmd);
int		sh_exec_pipedcmd(t_shell *sh, t_ast_node *ast);

#endif
