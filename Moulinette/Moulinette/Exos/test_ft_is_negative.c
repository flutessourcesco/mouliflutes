#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
    //printf("GO");
    if (argc < 2)
        return(0);
    ft_is_negative(atoi(argv[1]));
    return(0);
}
