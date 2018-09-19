#include "shell.h"

int		sh_unsetenv(t_cmd *cmd)
{
	char	**argv;

	if (cmd->argc < 2)
	{
		ft_putendl("Not enought args..");
		return (CMD_ERROR);
	}
	argv = &cmd->argv[1];
	while (*argv)
	{
		sh_env_del(cmd->shell->env->public, *argv);
		argv++;
	}
	return (CMD_SUCCESS);
}
