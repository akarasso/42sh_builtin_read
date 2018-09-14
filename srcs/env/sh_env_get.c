#include "read.h"

char	**sh_env_get_ref(char **tab, char *key)
{
	int	klen;
	int	i;

	if (!tab)
		return (0);
	klen = ft_strlen(key);
	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (!ft_strncmp(tab[i], key, klen) && tab[i][klen] == '=')
				return (&tab[i]);
			i++;
		}
	}
	return (0);
}

char	*sh_env_get(char **tab, char *key)
{
	int	klen;

	if (!tab || !key)
		return (0);
	klen = ft_strlen(key);
	while (*tab)
	{
		if (!ft_strncmp(*tab, key, klen) && (*tab)[klen] == '=')
			return (ft_strchr(*tab, '=') + 1);
		tab++;
	}
	return (0);
}

char	*env_get_first(t_env *env, char *key)
{
	char	*ret;

	if ((ret = sh_env_get(env->public, key)))
		return (ret);
	else if ((ret = sh_env_get(env->private, key)))
		return (ret);
	else if ((ret = sh_env_get(env->local, key)))
		return (ret);
	return (0);
}
