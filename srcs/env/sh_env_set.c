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

int		sh_env_set_protected(t_env *env, char *key, char *value)
{
	char	**ref;

	if (!key || !value || sh_env_get(env->private, key))
	{
		ft_putstr("42sh: read:'");
		ft_putstr(key);
		ft_putendl("' identifiant non valable");
		return (0);
	}
	else if ((ref = sh_env_get_ref(env->public, key)))
	{
		free(*ref);
		*ref = ft_3strjoinfree(key, "=", value, 0);
	}
	else
		sh_env_set(&env->local, key, value, 0);
	return (1);
}
