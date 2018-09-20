#include "shell.h"

static void prompt(t_shell *sh)
{
	char *cwd;
	char *home;

	home = env_get_first(sh->env, "HOME");
	if ((cwd = env_get_first(sh->env, "PWD")))
	{
		if (home && !ft_strcmp(home, cwd))
			ft_putstr("~");
		else
			ft_putstr(cwd);
	}
	ft_putstr("$>");
}

void		sh_input_loop(t_shell *sh)
{
	sh->cmd = 0;
	while (!sh->force_exit)
	{
		prompt(sh);
		get_next_line(0, &sh->cmd);
		sh_tokenize(sh);
		if (sh_parser(sh))
		{
			sh_ast_construct(sh);
			sh_exec(sh, sh->ast);
			sh_ast_del(&sh->ast);
			sh->lexer->first = 0;
			sh->lexer->last = 0;
			sh->lexer->len = 0;
		}
		else
			ft_dlst_clr(sh->lexer, sh_token_del);
		ft_strdel(&sh->cmd);
	}
}
