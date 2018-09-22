#include "shell.h"

static int		ft_open_redir(char *filepath, int mode)
{
	int fd;

	fd = -1;
	if (mode == LESS)
		fd = open(filepath, O_RDWR, 0666);
	else if (mode == GREAT)
		fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC, 0666);
	else if (mode == DGREAT)
		fd = open(filepath, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		ft_putendl("Shell:: Open error");
	return (fd);
}

static t_redir	*new_redir(t_int_token *io_number, int type_redir, t_str_token *to)
{
	t_redir *new;

	if(!(new = (t_redir*)malloc(sizeof(t_redir))))
		return (0);
	if (io_number->value == -1)
		io_number->value = (type_redir == LESS || type_redir == DLESS) ? 0 : 1;
	new->io_number = io_number->value;
	new->type = type_redir;
	new->to = to->value;
	return (new);
}

static int		heredoc_write(t_redir *redir)
{
	int		pfd[2];

	if (pipe(pfd) == -1)
		return (-1);
	write(pfd[1], redir->to, ft_strlen(redir->to));
	close(pfd[1]);
	if (dup2(pfd[0], redir->io_number) == -1)
		return (-1);
	close(pfd[0]);
	return (0);
}

static int		apply_redir(t_redir *redir)
{
	int fd;

	if (redir->type == LESSAND || redir->type == GREATAND)
	{
		// il y a quelque chose a propos des redirections ambigue ex 2>&file
		fd = ft_atoi(redir->to);
	}
	else if (redir->type == DLESS)
		fd = heredoc_write(redir);
	else
	{
		fd = ft_open_redir(redir->to, redir->type);
		if (dup2(fd, redir->io_number) == -1)
		{
			ft_putendl("Shell:: Failed to dup\n");
			return (0);
		}
	}
	if (fd < 0)
		return (0);
	return (1);
}

int		sh_build_redir(t_ast_node *ast, t_cmd *cmd)
{
	t_int_token	*tkn;
	t_dlst_elem	*elem;
	t_redir		*redir;

	elem = ast->token;
	while (elem)
	{
		tkn = (t_int_token*)elem->data;
		if (tkn->type == REDIRECT)
		{
			redir = new_redir(elem->prev->data, tkn->value, elem->next->data);
			ft_dlst_push(cmd->redir, redir);
			apply_redir(redir);
		}
		elem = elem->next;
	}
	return (1);
}
