#include "read.h"

int		read_flag(t_cmd *cmd, int *flag)
{
	int i;

	*flag = 0;
	if (argc > 1 && argv[1][0] == '-')
	{
		i = 1;
		while (argv[1][i])
		{
			if (argv[1][i] != 'r')
				return (0);
			*flag = 1;
			i++;
		}
	}
	return (1);
}

static void read_clear_str(char *str)
{
	while (*str)
	{
		if (!ft_isprint(*str) || *str == '\t') {
			*str = ' ';
		}
		str++;
	}
}

static char	**get_split_val(int flag)
{
	char **tab;
	char *res;
	char *line;

	line = 0;
	res = 0;
	get_next_line(0, &res);
	if (!flag)
	{
		while (get_next_line(0, &line) > 0)
		{
			res = ft_3strjoinfree(res, line, "\n", LEFT);
			ft_strdel(&line);
		}
	}
	read_clear_str(res);
	tab = (!flag) ? ft_strsplit(res, ' ') : ft_strsplit(res, ' ');
	free(res);
	return (tab)
}

int		sh_read(t_cmd *cmd)
{
	int 	flag;
	char	**tab;

	if (!read_flag(cmd, &flag))
	{
		printf("COMMAND ERROR FLAG\n");
		return (CMD_ERROR);
	}
	tab = get_split_val(flag);

	return (CMD_SUCCESS);
}
