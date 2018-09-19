#include "shell.h"


/*
** A note pour plus tard, que lors de la reprise d'une comande, 
** value vaut le contenu des token apres la prochaine newline jusqu'a 
** l'arrive du token heredoc de fin {Bugminor}
*/
static int	get_heredoc_value(t_dlst_elem *elem)
{
	char	*key;
	char	*line;
	char	*value;

	key = ((t_str_token*)elem->data)->value;
	line = 0;
	value = 0;
	while (1)
	{
		ft_putstr("heredoc>");
		get_next_line(0, &line);
		if (ft_strcmp(line, key))
			value = (!value) ? ft_strdup(line) : ft_3strjoinfree(value, "\n", line, LEFT);
		else
		{
			value = ft_strjoinfree(value, "\n", LEFT);
			break;
		}
		ft_strdel(&line);
	}
	ft_strdel(&key);
	ft_strdel(&line);
	((t_str_token*)elem->data)->value = value;
	return (1);
}

int		sh_heredoc(t_shell *sh)
{
	t_dlst_elem *elem;
	t_int_token	*tkn;

	elem = sh->lexer->first;
	while (elem)
	{
		tkn = (t_int_token*)elem->data;
		if (tkn->type == REDIRECT && tkn->value == DLESS)
		{
			if (!elem->next || ((t_str_token*)elem->next->data)->type != REDIRECT_PATH)
				return (0);
			get_heredoc_value(elem->next);
		}
		elem = elem->next;
	}
	return (1);
}