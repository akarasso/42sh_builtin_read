#include "read.h"

static int	read_flag(int argc, char ***argv, int *flag)
{
	int i;

	*flag = 0;
	if (argc > 1 && (**argv)[0] == '-' && (**argv)[1])
	{
		i = 1;
		while ((**argv)[i])
		{
			if ((**argv)[i] != 'r')
				return (0);
			*flag = 1;
			i++;
		}
	}
	if (*flag)
		(*argv)++;
	return (1);
}

static void	read_assign(t_cmd *cmd, char **argv, char **tab)
{
	char *tmp;

	while (*argv && *tab)
	{
		if (!*(argv + 1))
		{
			tmp = ft_strtab_join(tab, " ");
			sh_env_set_protected(cmd->env, *argv, tmp);
			ft_strdel(&tmp);
		}
		else
			sh_env_set_protected(cmd->env, *argv, *tab);
		tab++;
		argv++;
	}
}

static int	check_key(char **argv)
{
	while (*argv)
	{
		if (!sh_env_validkey(*argv))
		{
			ft_putstr("42sh: read: '");
			ft_putstr(*argv);
			ft_putendl("' identifiant non valable");
			return (0);
		}
		argv++;
	}
	return (1);
}

int			sh_read(t_cmd *cmd)
{
	int 	flag;
	char	**tab;
	char	**argv;

	argv = &cmd->argv[1];
	if (!read_flag(cmd->argc, &argv, &flag) || !check_key(argv))
		return (CMD_ERROR);
	tab = sh_read_get_split_val(flag);
	if (*argv)
		read_assign(cmd, argv, tab);
	else
		sh_env_set_protected(cmd->env, "REPLY", ft_strtab_join(tab, " "));
	ft_strtab_del(&tab);
	return (CMD_SUCCESS);
}
