#include "read.h"

int		sh_env_del(char **tab, char *key)
{
	int	klen;

	klen = ft_strlen(key);
	while (*tab)
	{
		if (!ft_strncmp(*tab, key, klen) && (*tab)[klen] == '=')
		{
			ft_strtab_del(&tab);
			return (1);
		}
		tab++;
	}
	return (0);
}
