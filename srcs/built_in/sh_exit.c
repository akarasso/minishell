#include "shell.h"

static int	sh_exit_error(t_cmd *cmd)
{
	if (cmd->argc > 2)
	{
		ft_putendl("Too many..");
		return (1);
	}
	if (cmd->argv[1] && !ft_strdigit(cmd->argv[1]))
	{
		ft_putendl("Only num char..");
		return (1);
	}
	return (0);
}

int		sh_exit(t_cmd *cmd)
{
	char	*str;
	int		ret;

	if (sh_exit_error(cmd))
		return (CMD_ERROR);
	str = (cmd->argv[1]) ? cmd->argv[1] : sh_env_get(cmd->shell->env->private, "?");
	if (!str)
		return (CMD_ERROR);
	ret = ft_atoi(str);
	// le foutre dans la structure du shell ou un truc
	return (ret);
}
