#include <stdio.h>
#include "argparse.h"

int main(int argc, char **argv)
{
	/*INIT*/
	arg_opt	options = arg_init(argc, argv);
	init_options(&options, 'v', "try", BOOL);
	init_options(&options, 'b', "bool", BOOL);
	init_options(&options, 'i', "int", INT);
	init_options(&options, 'c', "char", CHAR);
	init_options(&options, 'f', "float", FLOAT);
	
	/*HOW TO USE*/
	arg_start(&options); //recup les args sans les options
	void	*ret;
	if ((ret = find_options(&options, "bool")) != NULL)
		printf("bool true\n");
	free(ret);
	if ((ret = find_options(&options, "try")) != NULL)
		printf("bool2 true\n");
	free(ret);
	if ((ret = find_options(&options, "int")) != NULL)
		printf("%d\n", *(int*)ret);
	free(ret);
	if ((ret = find_options(&options, "char")) != NULL)
		printf("%s\n", (char*)ret);
	free(ret);
	if ((ret = find_options(&options, "float")) != NULL)
		printf("%f\n", *(float*)ret);	
	free(ret);

	/*CLEAN ALL THE MALLOC NEEDED*/
	arg_end(options);
}