#include "header.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
void    Test_Exo(char **argv, char *input)
{
    char *result;
    if (strcmp(argv[1],"ft_putstr") == 0)
    {
        result = strdup(al_putstr(argv[2]));
    }

    if (strcmp(input,result) == 0)
        printf("OK :)\n");
    else
        printf("KO :(\n");
}

int     main(int argc, char **argv)
{
    char *input = ft_read_file();
    if (argc == 1)
        return (0);
    Test_Exo(argv, input);
    write(1,&input[0],1);
    return (0);
}

