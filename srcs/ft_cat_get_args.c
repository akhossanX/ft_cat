#include "ft_cat.h"

static void	lookup_long_opt_table(t_cat *cat, const char *arg)
{
	int		i;

	i = 0;
	while (i < LOPTION_TABLE_LENGTH)
	{
		if (ft_strcmp(g_loptions[i].opt_name, arg) == 0)
		{
			if ((g_loptions[i].opt_code & OPT_VERSION) \
				|| (g_loptions[i].opt_code & OPT_HELP))
				version_or_help(cat, g_loptions[i].opt_code);
			cat->flags |= g_loptions[i].opt_code;
			return ;
		}
		i++;	
	}
	ft_dprintf(STDERR, "%s: unrecognized option '%s'\n", cat->prog, arg);
	ft_dprintf(STDERR, "Try './ft_cat --help' for more information.\n");
	ft_cat_terminate(cat, ERR_CAT_INVOPT);
}

static void	lookup_short_opt_table(t_cat *cat, const char *arg)
{
	int		i;
	int		valid;

	++arg;
	while (*arg)
	{
		valid = 0;
		i = 0;
		while (i < SOPTION_TABLE_LENGTH)
		{
			if (g_soptions[i].opt_name == *arg)
			{
				cat->flags |= g_soptions[i].opt_code;
				valid = 1;
				break ;
			}
			i++;
		}
		if (valid == 0)
		{
			ft_dprintf(STDERR, "%s: invalid option -- '%c'\n",\
			 cat->prog, *arg);
			ft_dprintf(STDERR, \
				"Try './ft_cat --help' for more information.\n");
			ft_cat_terminate(cat, ERR_CAT_INVOPT);
		}
		arg += 1;
	}
}

static void	get_input_file(t_cat *cat, const char *arg)
{
	t_file	*new;
	t_file	*ptr;

	new = cat_file_new(cat, arg);
	ptr = cat->files;
	if (ptr == NULL)
		cat->files = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	ft_cat_get_args(t_cat *cat)
{
	char	**s;
	int		opt_end;

	s = cat->args;
	opt_end = INT_MAX;
	cat->i = 0;
	while (s[cat->i])
	{
		if (opt_end == INT_MAX && ft_strcmp(s[cat->i], "--") == 0)
			opt_end = cat->i;
		else if (cat->i < opt_end && ft_strncmp(s[cat->i], "--", 2) == 0)
			lookup_long_opt_table(cat, s[cat->i]);
		else if (cat->i < opt_end && s[cat->i][0] == '-' && s[cat->i][1])
			lookup_short_opt_table(cat, s[cat->i]);
		else
			get_input_file(cat, s[cat->i]);
		cat->i += 1;
	}
	if (cat->files == NULL)
		get_input_file(cat, "-");
}
