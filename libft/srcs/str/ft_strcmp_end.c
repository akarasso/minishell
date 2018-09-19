#include "libft.h"

int		ft_strcmp_end(char *s1, char *s2)
{
	int	s1len;
	int	s2len;

	s1len = ft_strlen(s1) - 1;
	s2len = ft_strlen(s2) - 1;
	if (s1len < s2len)
		return (1);
	while (s2len > -1)
	{
		if (s2[s2len] != s1[s1len])
			return (s1[s1len] - s2[s2len]);
		s1len--;
		s2len--;
	}
	return (0);
}
