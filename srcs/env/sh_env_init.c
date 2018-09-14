#include "read.h"

t_env	*sh_env_init(char **env)
{
	t_env *new;

	if (!(new = (t_env*)ft_memalloc(sizeof(*new))))
		return (0);
	new->public = ft_strtab_dup(env);
	new->private = ft_strtab_new(1);
	new->local = ft_strtab_new(1);
	if (!new->public || !new->private || !new->local)
	{
		sh_env_deconstructor(new);
		return (0);
	}
	if (!sh_env_set(&new->private, "UID", ft_itoa(getuid()), RIGHT)
		|| !sh_env_set(&new->private, "?", "0", 0))
	{
		sh_env_deconstructor(new);
		return (0);
	}
	return (new);
}

void	sh_env_deconstructor(t_env *env)
{
	if (env)
	{
		if (env->public)
			ft_strtab_del(&env->public);
		if (env->private)
			ft_strtab_del(&env->private);
		if (env->local)
			ft_strtab_del(&env->local);
		free(env);
	}
}
