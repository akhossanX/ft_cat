
#include "ft_cat.h"

void	ft_cat_free(t_cat *cat)
{
	t_file	*f;
	t_file	*p;

	f = cat->files;
	while (f)
	{
		ft_strdel(&f->name);
		p = f;
		f = f->next;
		free(p);
	}
	free(cat);
}
