
#include "ft_cat.h"

void	ft_cat_terminate(t_cat *cat, const int err)
{
	int		code;

	ft_cat_free(cat);
	if (err > 0)
		ft_dprintf(STDERR, "%s: %s\n", cat->prog, strerror(err));
	if (err < 0)
		ft_dprintf(STDERR, "%s: %s\n", cat->prog, "cat_strerror"/*cat_strerror(cat, err)*/);	
	code = err == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
	exit(code);
}
