Argparse_C

- Includes
    
    ```c
    #include "arg.h"
    ```
    
- Init
    
    ```c
    /*Firstly create an arg_opt variable*/
    arg_opt	options;
    /*initialize it with arg_init(int argc, char **argv)*/
    options = arg_init(argc, argv);
    /*Add the options needed with 
    init_options(arg_opt *options, char flag, char *fullname, int type)*/
    init_options(&options, 'b', "bool", BOOL);
    init_options(&options, 'i', "int", INT);
    init_options(&options, 'c', "char", CHAR);
    init_options(&options, 'f', "float", FLOAT);
    //  BOOL  -> for a boolean
    //  INT   -> for an int
    //  CHAR  -> for a char*
    //  FLOAT -> for a float 
    ```
    
- Start
    
    ```c
    /*Start the program to check all the error in the input
    and get the arg without the flags*/
    arg_start(&options);
    /*The args without flag are stored in clean_arg*/
    ```
    
- Get the value of the flags
    
    ```c
    void   *ret;
    /*find_options return the value of the flag
    	ex: ./program -i 10 will return 10*/
    ret = find_options(&options, "int")
    if (ret != NULL)
    		/**/
    /*The value returned by find_options need to be free to avoid leaks*/
    free(ret);
    ```
    
- End
    
    ```c
    arg_end(options);
    /* To free all the struct */
    ```

- Use
    
    ```bash
    ./program -i 15 -f 1.0
    ./program -bc test
    	->with the options names
    	
    ./program --bool --int 10
    	->with the options fullname
    
    ```
