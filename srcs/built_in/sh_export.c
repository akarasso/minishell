#include "shell.h"

static int	export_vars(t_cmd *cmd, char *argv)
{
	char	*pos;
	char	*val;

	if ((pos = ft_strchr(argv, '=')))
	{
		*pos = 0;
		if (!sh_env_validkey(argv))
			return (1);
		sh_env_set(&cmd->shell->env->public, argv, pos + 1, 0);
	}
	else
	{
		if (!sh_env_validkey(argv))
			return (1);
		val = sh_env_get(cmd->shell->env->local, argv);
		sh_env_set(&cmd->shell->env->public, argv, val, 0);
	}
	sh_env_del(cmd->shell->env->local, argv);
	return (0);
}

int		sh_export(t_cmd *cmd)
{
	char	**argv;
	int		ret;

	ret = 0;
	if (cmd->argc < 2)
	{
		ft_putendl("Too few args..");
		return (CMD_ERROR);
	}
	else
	{
		argv = &cmd->argv[1];
		while (*argv)
		{
			ret += export_vars(cmd, *argv);
			argv++;
		}
	}
	return ((ret) ? CMD_ERROR : CMD_SUCCESS);
}
