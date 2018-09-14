#include "read.h"

int		sh_env_validkey(char *s)
{
	if (!s || ft_isdigit(*s) == 1)
		return (0);
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}
