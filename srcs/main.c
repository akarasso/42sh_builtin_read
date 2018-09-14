#include "read.h"

int main(int argc, char **argv, char **ienv)
{
	t_env	*env;
	t_cmd	cmd;

	if (!(env = sh_env_init(ienv)))
		return (1);
	cmd.argv = ft_strtab_dup(argv);
	cmd.argc = argc;
	cmd.env = env;
	sh_read(&cmd);
	return (0);
}
