#include "shell.h"

int			sh_exec_terminator(t_shell *sh, t_ast_node *node)
{
	int ret;

	ret = 0;
	if (node->left)
		ret = sh_exec(sh, node->left);
	if (node->right)
		ret = sh_exec(sh, node->right);
	return (ret);
}

int			sh_exec_logical(t_shell *sh, t_ast_node *node, int logical)
{
	if (logical == DAND && (sh_exec(sh, node->left) != CMD_SUCCESS
		|| sh_exec(sh, node->right) != CMD_SUCCESS))
		return (CMD_ERROR);
	else if (logical == OR && sh_exec(sh, node->left) != CMD_SUCCESS
		&& sh_exec(sh, node->right) != CMD_SUCCESS)
		return (CMD_ERROR);
	return (CMD_SUCCESS);
}

int			sh_exec(t_shell *sh, t_ast_node *node)
{
	int logical;
	int	ret;

	if (node && node->token)
	{
		if (is_terminator(node->token->data))
			return (sh_exec_terminator(sh, node));
		else if ((logical = is_logical(node->token->data)))
			return (sh_exec_logical(sh, node, logical));
		else if (is_pipe(node->token->data))
			return (sh_exec_pipedcmd(sh, node));
		else
		{
			ret = sh_exec_cmd(sh, node);
			if (!(sh_env_set(&sh->env->private, "?", ft_itoa(ret), RIGHT)))
				ret = CMD_ERROR;
			return (ret);
		}
	}
	return (CMD_SUCCESS);
}
