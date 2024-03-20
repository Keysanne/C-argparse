#include "argparse.h"

void    *value(int j, int type, arg_opt *options, char *opt, char *fullname_opt)
{
    switch(type)
    {
        case BOOL:;
             bool *x = malloc(sizeof(bool));
            *x = true;
            return x;
        case CHAR:
            if (j + 1 < options->nb_arg)
            {
                if(valid_str(options->arg[j + 1]))
                    return strdup(options->arg[j + 1]);
            }
            printf("invalid argument with %s/%s options\n", opt, fullname_opt);
            break;
        case INT:
            if (j + 1 < options->nb_arg)
            {
                if(valid_int(options->arg[j + 1]))
                {
                    int *x = malloc(sizeof(int));
                    *x = atoi(options->arg[j + 1]);
                    return x;
                }
            }
            printf("invalid argument with %s/%s options\n", opt, fullname_opt);
            break;
        case FLOAT:
            if (j  + 1 < options->nb_arg)
            {
                if(valid_float(options->arg[j + 1]))
                {
                    float *x = malloc(sizeof(int));
                    *x = atof(options->arg[j + 1]);
                    return x;
                }
            }
            printf("invalid argument with %s/%s options\n", opt, fullname_opt);
            break;
    }
    return NULL;
}

void    *find_options(arg_opt *tab, char *opt)
{
    int i;
    char *tmp = strjoin("--", opt);
    for(i = 0; i < tab->nb_options; i++)
    {
        if(strcmp(tab->options[i].fullname_opt, tmp) == 0)
            break ;
    }
    if(strcmp(tab->options[i].fullname_opt, tmp) != 0)
    {
        free(tmp);
        return NULL;
    }
    free(tmp);
    for(int j = 0; tab->arg[j]; j++)
    {
        if(strcmp(tab->arg[j], tab->options[i].opt) == 0 || strcmp(tab->arg[j], tab->options[i].fullname_opt) == 0)
            return value(j, tab->options[i].type, tab, tab->options[i].opt, tab->options[i].fullname_opt);
            //is_here for an easier clean
    }
    return NULL;
}

bool    add_to_options(arg_opt *tab, options opt)
{
    tab->options = realloc(tab->options, (tab->nb_options + 1) * sizeof(options));
    if (tab->options == NULL)
        return false;
    tab->options[tab->nb_options] = opt;
    tab->nb_options += 1;
    return true;
}

bool init_options(arg_opt *tab, char opt, char *fullname_opt, int type)
{
    options new;
    if (isalpha(opt) == 0)
        return false;
    if (type != BOOL && type != INT && type != CHAR && type != FLOAT)
        return false;
    new.type = type;
    char    *op = to_str(opt);
    new.opt = strjoin("-", op);
    free(op);
    if (fullname_opt != NULL)
        new.fullname_opt = strjoin("--", fullname_opt);
    if (!add_to_options(tab, new))
        return false;
    return true;
}