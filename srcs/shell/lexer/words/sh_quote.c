/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:45:44 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:45:44 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (*ptr == '\\')
			ptr++;
		else if (*ptr == q)
			break ;
		if (*ptr)
			ptr++;
	}
	*str = ptr;
}

int		quote_str_valid(char *s)
{
	char	c;

	while (*s)
	{
		if (*s == '\\')
			s++;
		else if (is_quote(*s))
		{
			c = *s;
			goto_next_quote(&s);
			if (!is_quote(*s))
				return (c);
		}
		s++;
	}
	return (0);
}
