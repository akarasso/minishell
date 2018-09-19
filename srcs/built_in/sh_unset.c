#include "shell.h"

int		sh_unset(t_cmd *cmd)
{
	char	**argv;
	int		ret;

	if (cmd->argc < 2)
	{
		ft_putendl("Not enought args..");
		return (CMD_ERROR);
	}
	argv = &cmd->argv[1];
	ret = CMD_SUCCESS;
	while (argv)
	{
		sh_env_set_protected(cmd->shell->env, *argv, *(argv + 1));
		argv++;
	}
	return (ret);
}
