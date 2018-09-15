#include "read.h"

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

static int	is_end_read(char *str)
{
	char escape;

	escape = 0;
	while (*str)
	{
		if (!escape && *str == '\\')
		{
			str++;
			escape = 1;
		}
		else
		{
			str++;
			escape = 0;
		}
	}
	return (escape) ? 0 : 1;
}

static void read_rm_escape(char *s)
{
	while (*s)
	{
		if (*s == '\\')
		{
			ft_strrmvchr(s);
			if (*s)
				s++;
		}
		else
			s++;
	}
}

static void		read_opt_no_opt(char **res)
{
	char *line;
	char stop;

	stop = 0;
	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (is_end_read(line))
			stop = 1;
		else
			ft_strrmvchr(ft_strlastchr(line));
		*res = ft_3strjoinfree(*res, line, " ", LEFT);
		ft_strdel(&line);
		if (stop)
			break ;
	}
	read_rm_escape(*res);
}

char			**sh_read_get_split_val(int flag)
{
	char **tab;
	char *res;

	res = 0;
	if (flag)
		get_next_line(0, &res);
	else
		read_opt_no_opt(&res);
	read_clear_str(res);
	tab = ft_strsplit(res, ' ');
	ft_strdel(&res);
	return (tab);
}
