#include "shell.h"

char	*g_shell_op[7] = {";", "&", "|", "||", "&&", 0};

char	*g_shell_redirect[10] = {
	"<", ">", "<<", ">>", "<&",
	">&", 0
};
