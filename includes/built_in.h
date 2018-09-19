#ifndef BUILT_IN_H
# define BUILT_IN_H

typedef struct	s_cmd
{
	t_dlst	*redir;
	t_shell	*shell;
	t_env	*env;
	int		saved_fd[3];
	char	**argv;
	char	*name;
	int		argc;
}				t_cmd;

typedef struct	s_func
{
	char		*name;
	int 		(*func)(t_cmd*);
}				t_func;

int				built_in_cmp(void *data, void *name);
t_func			*built_in_new(char *key, int (*func)(t_cmd*));
int				built_in_find(void *data, void *data2);
int				sh_cd(t_cmd *cmd);
int				sh_echo(t_cmd *cmd);
int				sh_env(t_cmd *cmd);
int				sh_exit(t_cmd *cmd);
int				sh_export(t_cmd *cmd);
int				sh_setenv(t_cmd *cmd);
int				sh_unset(t_cmd *cmd);
int				sh_unsetenv(t_cmd *cmd);
char			**sh_read_get_split_val(int flag);

#endif
