#ifndef READ_H
# define READ_H

# include "libft.h"

# define CMD_ERROR 1
# define CMD_SUCCESS 0

/*
** Import struct
*/

typedef struct	s_env
{
	char	**public;
	char	**private;
	char	**local;
}				t_env;

typedef struct	s_cmd
{
	char	**argv;
	t_env	*env;
	int		argc;
}				t_cmd;

int		sh_read(t_cmd *cmd);
char	**sh_read_get_split_val(int flag);

/*
** ENV
*/

int		sh_env_del(char **tab, char *key);
char	**sh_env_get_ref(char **tab, char *key);
char	*sh_env_get(char **tab, char *key);
char	*env_get_first(t_env *env, char *key);
t_env	*sh_env_init(char **env);
void	sh_env_deconstructor(t_env *env);
int		sh_env_set(char	***tab, char *key, char *value, char flag);
int		sh_env_validkey(char *s);
int		sh_env_set_protected(t_env *env, char *key, char *value);

#endif
