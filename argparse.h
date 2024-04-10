#ifndef ARGPARSE_H
# define ARGPARSE_H

#include "arg.h"

char    *strjoin(char *s1, char *s2);
char    **arg_without_opt(char **arg, arg_opt *tab);
char*   to_str(char c);
bool    check_opt(char opt);
bool    multiple_flags(options opt, char *arg, arg_opt *tab);
bool    valid_str(char *str);
bool    valid_float(char *str);
bool    valid_int(char *str);
bool    is_multiple_flags(char **arg, int x, arg_opt tab);
void    update_arg(arg_opt *tab, int j, int type);
void    multiple_definition(arg_opt *tab, int i, int *valid);
bool    only_tiret(char *str);

#endif
