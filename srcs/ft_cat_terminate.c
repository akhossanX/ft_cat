
#include "ft_cat.h"

void	ft_cat_terminate(t_cat *cat, const int err)
{
	int		code;

	if (err == ENOMEM)
		ft_dprintf(STDERR, "%s: %s\n", cat->prog, strerror(err));
	else if (err > 0) 
	{
		ft_dprintf(STDERR, "%s: %s: %s\n", cat->prog,\
			 cat->buff, strerror(err));
	}
	ft_cat_free(cat);
	code = err == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
	exit(code);
}
