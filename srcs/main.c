
#include "ft_cat.h"

static t_cat	*ft_cat_init(char **args)
{
	t_cat	*cat;

	errno = 0;
	cat = (t_cat *)ft_memalloc(sizeof(t_cat));	
	if (cat == NULL)
		ft_cat_terminate(cat, errno);
	cat->fd = STDIN;
	cat->nb = 1;
	cat->prog = args[0];
	cat->args = &args[1];
	return (cat);
}

int				main(int argc, char *argv[])
{
	t_cat	*cat;
	t_file	*file;

	(void)argc;
	cat = ft_cat_init(argv);
	ft_cat_get_args(cat);
	file = cat->files;
	while(file)
	{
		ft_cat_open_file(cat, file);
		ft_cat_file(cat, file);
		file = file->next;
	}
	ft_cat_terminate(cat, EXIT_SUCCESS);
	return (0);
}
