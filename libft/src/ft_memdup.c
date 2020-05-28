
#include "libft.h"

void	*ft_memdup(const void *s, size_t n)
{
	void	*mem;

	mem = ft_memalloc(n);
	if (mem == NULL)
		return (NULL);
	ft_memmove(mem, s, n);
	return (mem);
}
