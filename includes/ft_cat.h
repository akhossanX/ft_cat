#ifndef FT_CAT_H
# define FT_CAT_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>
# include <fcntl.h>

#define LOPTION_TABLE_LENGTH	9
#define SOPTION_TABLE_LENGTH	9

# define OPT_B			(1 << 0)
# define OPT_CAPE		(1 << 1)
# define OPT_N			(1 << 2)
# define OPT_S			(1 << 3)
# define OPT_CAPT		(1 << 4)
# define OPT_V			(1 << 5)
# define OPT_HELP		(1 << 6)
# define OPT_VERSION	(1 << 7)


# define ERR_CAT_INVOPT	-1

typedef struct		l_soption
{
	char			opt_name;
	unsigned int	opt_code;
}					t_soption;

typedef struct		s_loption
{
	char			*opt_name;
	unsigned int	opt_code;
}					t_loption;

extern const t_soption	g_soptions[];
extern const t_loption	g_loptions[];

typedef struct		s_file
{
	char			*name;
	struct s_file	*next;
}					t_file;

typedef struct		s_cat
{
	unsigned short	flags;
	int				fd;
	int				i;
	int				opt_end;
	int				size;
	int				empty;
	int				nb;
	char			**args;
	char			*buff;
	const char		*prog;
	t_file			*files;
}					t_cat;

extern const char	*g_form_table[];

void	ft_cat_get_args(t_cat *cat);
void	ft_cat_free(t_cat *cat);
void	ft_cat_terminate(t_cat *cat, const int err);
void	version_or_help(t_cat *cat, const int code);
t_file	*cat_file_new(t_cat *cat, const char *filename);
void	ft_cat_open_file(t_cat *cat, t_file *file);
void	ft_cat_file(t_cat *cat, t_file *file);

#endif
