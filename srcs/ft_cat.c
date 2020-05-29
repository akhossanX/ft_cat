
#include "ft_cat.h"

t_file		*cat_file_new(t_cat *cat, const char *filename)
{
	t_file	*file;

	errno = 0;
	file = (t_file *)ft_memalloc(sizeof(t_file));
	if (file == NULL)
		ft_cat_terminate(cat, errno);	
	file->name = ft_strdup(filename);
	if (file->name == NULL)
		ft_cat_terminate(cat, errno);
	return (file);
}

void	ft_cat_open_file(t_cat *cat, t_file *file)
{
	if (ft_strcmp(file->name, "-") == 0)
		cat->fd = STDIN;
	else
	{
		errno = 0;
		cat->fd = open(file->name, O_RDONLY);
	}
	if (cat->fd == -1)
	{
		cat->buff = file->name;
		ft_cat_terminate(cat, errno);
	}
}

void	ft_cat_display_file(t_cat *cat)
{
	size_t	i;
	char	*s;

	cat->flags == 0 ? write(1, cat->buff, cat->size) : 0;
	if (((cat->flags & OPT_S) && cat->empty > 1) || cat->flags == 0)
		return ;
	(cat->flags & OPT_B) && !cat->empty ? ft_printf("%6d  ", cat->nb++) : 0;
	(cat->flags & OPT_N) ? ft_printf("%6d  ", cat->nb++) : 0;
	i = 0;
	while (i < (size_t)cat->size)
	{
		if (cat->buff[i] == '\n' && (cat->flags & OPT_CAPE))
			write(1, "$\n", 2);
		else if (cat->buff[i] == '\t' && (cat->flags & OPT_CAPT))
			write(1, "^I", 2);
		else if ((cat->flags & OPT_V) && ft_iscntrl(cat->buff[i]))
		{
			s = (char *)g_form_table\
				[cat->buff[i] < 0 ? cat->buff[i] + 256 : cat->buff[i]];
			write(1, s, ft_strlen(s));	
		}
		else
			write(1, &cat->buff[i], 1);
		i++;
	}
}

void	ft_cat_file(t_cat *cat, t_file *file)
{
	cat->size = -1;
	if ((cat->flags & OPT_B) && (cat->flags & OPT_N))
		cat->flags ^= OPT_N;
	errno = 0;
	cat->empty = 0;
	while ((cat->size = ft_getline(cat->fd, &cat->buff)) > 0)
	{
		if (cat->size == 1 && *cat->buff == '\n')
			cat->empty += 1;
		else
			cat->empty = 0;
		ft_cat_display_file(cat);
		ft_strdel((char **)&cat->buff);
	}
	if (cat->size == -1)
	{
		cat->buff = file->name;
		ft_cat_terminate(cat, errno);
	}
}
