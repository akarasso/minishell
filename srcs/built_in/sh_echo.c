#include "shell.h"

static int	check_flag(char ***argv)
{
	int		i;
	int		flag;
	char	**ptr;

	ptr = *argv;
	i = 0;
	flag = 0;
	while (ptr[i] && ptr[i][0] == '-')
	{
		if (!ft_str_onlychr(&ptr[i][1], "n"))
		{
			if (i > 1)
				i--;
			break ;
		}
		if (!flag && ptr[i][1] == 'n')
			flag = 1;
		i++;
	}
	*argv = ptr + i;
	return (flag);
}

int		sh_echo(t_cmd *cmd)
{
	int		flag;
	char	**argv;

	if (cmd->argc > 1)
	{
		argv = &cmd->argv[1];
		flag = check_flag(&argv);
		while (*argv)
		{
			write(1, *argv, ft_strlen(*argv));
			if (*(argv + 1))
				write(1, " ", 1);
			argv++;
		}
		if (!flag)
			write(1, "\n", 1);
	}
	return (CMD_SUCCESS);
}
