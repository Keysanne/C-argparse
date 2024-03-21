#ifndef ARGPARSE_C
# define ARGPARSE_C

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BOOL 0
#define INT 1
#define CHAR 2
#define FLOAT 3

typedef struct  arg_opt
{
    struct options  *options;
    int             nb_options;
    char            **arg;
    int             nb_arg;
}   arg_opt;

typedef struct  options
{
    char    *opt;
    char    *fullname_opt;
    int     type;
    bool    is_here;
}   options;

arg_opt arg_init(int argc, char **argv);
void    arg_start(arg_opt *tab);
void	arg_end(arg_opt tab);
bool    init_options(arg_opt *tab, char opt, char *fullname_opt, int type);
void    *find_options(arg_opt *tab, char *opt);
char    *strjoin(char *s1, char *s2);
bool    check_opt(char opt);
bool    multiple_flags(options opt, char *arg, arg_opt *tab);
bool    valid_str(char *str);
bool    valid_float(char *str);
char*   to_str(char c);
bool    valid_int(char *str);
void    update_arg(arg_opt *tab, int j, int type);
bool    is_multiple_flags(char **arg, int x, arg_opt tab);
void    multiple_definition(arg_opt *tab, int i, int *valid);

#endif