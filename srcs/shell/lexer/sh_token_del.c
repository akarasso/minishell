#include "shell.h"

void	sh_token_del(void *data)
{
	t_str_token *tkn;

	tkn = (t_str_token*)data;
	if (tkn->type & (OP | IO_NUMBER | REDIRECT) )
		ft_del_chr_token((t_chr_token**)&data);
	else
		ft_del_str_token((t_str_token**)&data);
}