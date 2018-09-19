#include "shell.h"

int		ft_get_cmdret(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_putendl_fd("Segmentation Fault", 2);
		else if (WTERMSIG(status) == SIGBUS)
			ft_putendl_fd("Bus Error", 2);
		else if (WTERMSIG(status) == SIGABRT)
			ft_putendl_fd("Abort", 2);
	}
	return (CMD_ERROR);
}

static int	sh_exec_fork(t_shell *sh, t_cmd *cmd)
{
	pid_t	pid;
	char	*fullpath;
	int		ret;

	ret = CMD_SUCCESS;
	if ((pid = fork()) == -1)
		return (CMD_ERROR);
	else if (pid == 0)
	{
		fullpath = sh_bin_path(sh, cmd->argv[0], &ret);
		if (fullpath)
			execve(fullpath, cmd->argv, 0);
		return (ret);
	}
	else if (pid > 0)
		waitpid(pid, &ret, WUNTRACED);
	return (ft_get_cmdret(ret));
}

int		sh_exec_cmd(t_shell *sh, t_ast_node *ast)
{
	t_cmd	*cmd;
	t_func	*node;
	int		ret;

	if (ast)
	{
		ret = CMD_SUCCESS;
		if (!(cmd = sh_new_cmd(sh, ast->token)))
			return (CMD_ERROR);
		sh_expansion(cmd);
		sh_std_save(cmd->saved_fd);
		sh_build_redir(ast, cmd);
		if ((node = ft_btree_find(sh->func, built_in_find, cmd->argv[0])))
			ret = node->func(cmd);
		else
			ret = sh_exec_fork(sh, cmd);
		sh_std_restore(cmd->saved_fd);
		sh_del_cmd(&cmd);
		return (ret);
	}
	return (CMD_SUCCESS);
}
