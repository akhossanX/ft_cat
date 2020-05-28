
#include "ft_cat.h"

t_cat	*ft_cat_init(char **args)
{
	t_cat	*cat;

	errno = 0;
	cat = (t_cat *)ft_memalloc(sizeof(t_cat));	
	if (cat == NULL)
		ft_cat_terminate(cat, errno);
	cat->fd = STDIN;
	cat->prog = args[0];
	cat->args = &args[1];
	return (cat);
}

void	ft_cat_open_file(t_cat *cat, const char *filename)
{
	if (ft_strcmp(filename, "-") == 0)
		cat->fd = STDIN;
	else
	{
		errno = 0;
		cat->fd = open(filename, O_RDONLY);
		if (cat->fd == -1)
			ft_cat_terminate(cat, errno);
	}
}

void	ft_cat_display_file(t_cat *cat)
{
	size_t	i;
	char	*s;

	if ((cat->flags & OPT_S) && cat->empty > 1)
		return ;
	if (cat->flags & OPT_B)
		cat->empty == 0 ? ft_printf("%6d  ", cat->nb++) : 0;
	else if (cat->flags & OPT_N)
		ft_printf("%6d  ", cat->nb++);
	i = -1;
	while (++i < cat->size)
	{
		if (cat->buff[i] == '\n' && cat->flags & OPT_CAPE)
			write(1, "$\n", 2);
		else if (cat->buff[i] == '\t' && cat->flags & OPT_CAPT)
			write(1, "^I", 2);
		else if (cat->flags & OPT_V && iscntrl(cat->buff[i]))
		{
			s = (char *)g_form_table[(unsigned)cat->buff[i]];
			write(1, s, ft_strlen(s));	
		}
		else
			write(1, &cat->buff[i], 1);
	}
}

void	ft_cat_file(t_cat *cat)
{
	cat->size = -1;
	if (cat->flags &  OPT_B)
		cat->flags ^= OPT_N;
	errno = 0;
	cat->nb = 1;
	cat->empty = 0;
	while ((cat->size = ft_getline(cat->fd, &cat->buff)) > 0)
	{
		if (cat->size == 1 && *cat->buff == '\n')
			cat->empty += 1;
		else
			cat->empty = 0;
		ft_cat_display_file(cat);
		ft_strdel(&cat->buff);
	}
	if (cat->size == -1)
		ft_cat_terminate(cat, errno);
}

int		main(int argc, char *argv[])
{
	t_cat	*cat;
	t_file	*file;

	(void)argc;
	cat = ft_cat_init(argv);
	ft_cat_get_args(cat);
	file = cat->files;
	while(file)
	{
		ft_cat_open_file(cat, file->name);
		ft_cat_file(cat);
		file = file->next;
	}
	ft_cat_terminate(cat, EXIT_SUCCESS);
	return (0);
}
