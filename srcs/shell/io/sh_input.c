#include "shell.h"

void		sh_input_loop(t_shell *sh)
{
	sh->cmd = 0;
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &sh->cmd);
		sh_tokenize(sh);
		if (sh_parser(sh))
		{
			sh_ast_construct(sh);
			sh_exec(sh, sh->ast);
		}
		else
			ft_putendl("Commande invallide\n");
		ft_dlst_clr(sh->lexer, sh_token_del);
		sh_ast_del(&sh->ast);
		ft_strdel(&sh->cmd);
	}
}
