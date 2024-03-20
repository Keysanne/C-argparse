#include "argparse.h"
#include <stdbool.h>


char    *strjoin(char *s1, char *s2)
{
    int j = 0;
    char *rst = malloc(strlen(s1) + strlen(s2) + 1);
    for(int i = 0; s1[i];i++)
        rst[j++] = s1[i];
    for(int i = 0; s2[i];i++)
        rst[j++] = s2[i];
    rst[j] = 0;
    return rst;
}

arg_opt init(int argc, char **argv)
{
    arg_opt new;
    new.options = NULL;
    new.nb_options = 0;
    new.arg = malloc(argc * sizeof(char *));
    int i = 0;
    for(int j = 1; j < argc; j++)
        new.arg[i++] = strdup(argv[j]);
    new.arg[i] = 0;
    new.nb_arg = argc - 1;
    return new;
}

void	free_options(arg_opt tab)
{
    for (int i = 0; i < tab.nb_options; i++)
    {
        free(tab.options[i].opt);
        free(tab.options[i].fullname_opt);
    }
    free(tab.options);
    for(int i = 0; tab.arg[i]; i++)
        free(tab.arg[i]);
    free(tab.arg);
    exit(1);
}

bool    valid_str(char *str)
{
    if(str[0] == '-')
        return false;
    return true;
}

bool    valid_int(char *str)
{
    if (str[0] == '-' || isdigit(str[0]))
    {
        for(int i = 1; str[i]; i++)
            if(!isdigit(str[i]))
                return false;
        return true;
    }
    return false;
}

bool    valid_float(char *str)
{
    bool    dot = false;
    if (str[0] == '-' || isdigit(str[0]))
    {
        for(int i = 1; str[i]; i++)
        {
            if(!isdigit(str[i]))
            {
                if(str[i] == '.' && dot == false)
                {
                    dot = true;
                    continue;
                }
                return false;
            }
        }
    }
    return true;
}

char*   to_str(char c)
{
    char    *rst = malloc(2);
    rst[0] = c;
    rst[1] = 0;
    return rst;
}