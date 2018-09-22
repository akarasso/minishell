/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipedcmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:15 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:51:36 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	exec_piped_rec(t_shell *sh, t_ast_node *ast)
{
	int			pfd[2];
	pid_t		pid;

	pipe(pfd);
	if ((pid = fork()) == -1)
		ft_putendl("Erreur fork");
	else if (!pid)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT);
		exit(sh_exec_cmd(sh, ast->left));
	}
	else if (pid > 0)
	{
		close(pfd[1]);
		dup2(pfd[0], STDIN);
		if (ast && ast->right && ast->right->token
			&& is_pipe(ast->right->token->data))
			exit(exec_piped_rec(sh, ast->right));
		exit(sh_exec_cmd(sh, ast->right));
	}
	return (0);
}

int			sh_exec_pipedcmd(t_shell *sh, t_ast_node *ast)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	if ((pid = fork()) == -1)
		printf("Error fork\n");
	else if (!pid)
		exec_piped_rec(sh, ast);
	else if (pid > 0)
		waitpid(pid, &ret, WUNTRACED);
	return (ret);
}
