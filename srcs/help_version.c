
#include "ft_cat.h"

const char	g_ft_cat_version[] = \
"./ft_cat 0.0.2020\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\n\
Written by Abdelilah Khossan.\
";

const char	g_ft_cat_help[] = 
"Usage: ./ft_cat [OPTION]... [FILE]...\n\
Concatenate FILE(s) to standard output.\n\
\n\
With no FILE, or when FILE is -, read standard input.\n\
\n\
  -A, --show-all           equivalent to -vET\n\
  -b, --number-nonblank    number nonempty output lines, overrides -n\n\
  -e                       equivalent to -vE\n\
  -E, --show-ends          display $ at end of each line\n\
  -n, --number             number all output lines\n\
  -s, --squeeze-blank      suppress repeated empty output lines\n\
  -t                       equivalent to -vT\n\
  -T, --show-tabs          display TAB characters as ^I\n\
  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n\
      --help     display this help and exit\n\
      --version  output version information and exit\n\
\n\
Examples:\n\
  cat f - g  Output f's contents, then standard input, then g's contents.\n\
  cat        Copy standard input to standard output.\
";

void	version_or_help(t_cat *cat, const int code)
{
	if (code & OPT_VERSION)
		ft_printf("%s\n", g_ft_cat_version);
	if (code & OPT_HELP)
		ft_printf("%s\n", g_ft_cat_help);
	ft_cat_terminate(cat, 0);
}
