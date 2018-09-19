#include "shell.h"

static void	remove_env(char ***argv, t_shell *new)
{
	char	**ptr;
	int		flag;

	ptr = *argv;
	flag = 0;
	while (*ptr && (!ft_strcmp(*ptr, "-u") || !ft_strcmp(*ptr, "--unset")
		|| !ft_strcmp(*ptr, "-i")))
	{
		if (*ptr && !ft_strcmp(*ptr, "-i"))
		{
			flag = 1;
			ptr++;
		}
		else if (*(++ptr))
			sh_env_del(new->env->public, *ptr++);
	}
	if (flag)
	{
		ft_strtab_del(&new->env->public);
		new->env->public = ft_strtab_new(0);
	}
	*argv = ptr;
}

static void	modify_env(char ***argv, t_shell *new)
{
	char	**ptr;
	char	*pos;

	ptr = *argv;
	while (*ptr && (pos = ft_strchr(*ptr, '=')))
	{
		*pos = 0;
		sh_env_set(&new->env->public, *ptr, pos + 1, 0);
		ptr++;
	}
	*argv = ptr;
}

static int	exec_built_in(char *line, t_shell *shell)
{
	if (shell && line) {
		/* code */
	}
	/*sh_tokenize(shell);
	if (sh_parser(shell))
	{
		sh_ast_construct(shell);
		return (sh_exec(shell, shell->ast));
	}*/
	return (CMD_ERROR);
}

int		sh_env(t_cmd *cmd)
{
	t_shell *new;
	char		*line;
	char		**argv;

	// if (!(new = get_new_shell(cmd->shell->env->public)))
	if (!(new = 0))
		return (CMD_ERROR);
	argv = &cmd->argv[1];
	remove_env(&argv, new);
	modify_env(&argv, new);
	if (!*argv)
		ft_strtab_print(new->env->public);
	else
	{
		line = 0;
		while (*argv)
		{
			line = ft_3strjoinfree(line, " ", *argv, LEFT | RIGHT);
			argv++;
		}
		return (exec_built_in(line, new));
	}
	return (1);
}
