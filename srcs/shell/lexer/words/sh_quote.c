int		is_quote(char c)
{
	if (c == '\''
		|| c == '"')
		return (1);
	return (0);
}

void	goto_next_quote(char **str)
{
	char	*ptr;
	char	q;

	ptr = *str;
	q = *ptr;
	ptr++;
	while (*ptr)
	{
		if (*ptr == q)
			break ;
		if (*ptr == '/')
			ptr++;
		ptr++;
	}
	*str = ptr;
}

int		quote_str_valid(char *s)
{
	char	c;

	while (*s)
	{
		if (is_quote(*s))
		{
			c = *s;
			goto_next_quote(&s);
			if (!is_quote(*s))
				return (c);
		}
		if (*s == '\\')
			s++;
		s++;
	}
	return (0);
}
