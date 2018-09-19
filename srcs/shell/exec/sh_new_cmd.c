#include "shell.h"

static void	fill_cmd_argv(void *data, void *acc)
{
	t_str_token	*tkn;
	char		***tab;

	tab = (char ***)acc;
	tkn = (t_str_token*)data;
	if (tkn->type == WORD && *tab
		&& !(ft_strtab_add(tab, ft_strdup(tkn->value))))
			ft_strtab_del(tab);
}

t_cmd		*sh_new_cmd(t_shell *sh, t_dlst_elem *token_lst)
{
	t_cmd *cmd;

	if (!(cmd = (t_cmd*)ft_memalloc(sizeof(*cmd))))
		return (0);
	if (!(cmd->argv = ft_strtab_new(0)))
		return (0);
	if (!(cmd->redir = ft_dlst_new(0)))
		return (0);
	ft_dlstelem_reduce_data(token_lst, fill_cmd_argv, &cmd->argv);
	cmd->argc = ft_strtab_len(cmd->argv);
	if (!cmd->argv || !cmd->argc)
	{
		free(cmd);
		return (0);
	}
	cmd->shell = sh;
	cmd->env = sh->env;
	cmd->name = cmd->argv[0];
	return (cmd);
}