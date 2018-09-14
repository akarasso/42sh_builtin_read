#include "read.h"

int		sh_env_set(char	***tab, char *key, char *value, char flag)
{
	char	**env;
	char	*new;

	if (!key || !value)
		return (0);
	if (!(new = ft_3strjoinfree(key, "=", value, flag)))
		return (0);
	if ((env = sh_env_get_ref(*tab, key)))
	{
		free(*env);
		*env = new;
	}
	else if (!ft_strtab_add(tab, new))
	{
		free(new);
		return (0);
	}
	return (1);
}
