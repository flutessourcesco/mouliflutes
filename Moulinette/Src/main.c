#include "header.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void    Test_Exo(char **argv, char *input)
{
    char *result;
    if (strcmp(argv[1],"ft_putstr") == 0)
    {
        result = strdup(al_putstr(argv[2]));
    }
    if (strcmp(argv[1],"ft_print_alphabet") == 0)
    {
        result = strdup("abcdefghijklmnopqrstuvwxyz");
    }
    if (strcmp(argv[1],"ft_print_reverse_alphabet") == 0)
    {
        result = strdup("zyxwvutsrqponmlkjihgfedcba");
    }
    if (strcmp(argv[1],"ft_print_numbers") == 0)
    {
        result = strdup("0123456789");
    }
    if (strcmp(argv[1],"ft_is_negative") == 0)
    {
        if (argv[2][0] >= '0')
            result = strdup("P");
        else
            result = strdup("N");
    }
    if (strcmp(argv[1],"ft_print_comb") == 0)
    {
        result = strdup(al_print_comb());
    }
    if (strcmp(argv[1],"ft_print_comb2") == 0)
    {
        result = strdup(al_print_comb2());
    }
    if (strcmp(argv[1],"ft_putnbr") == 0)
    {
        result = strdup(argv[2]);
    }
    if (strcmp(argv[1],"ft_print_combn") == 0)
    {
        result = strdup(al_print_combn(atoi(argv[2])));
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
    //write(1,&input[0],1);
    return (0);
}

