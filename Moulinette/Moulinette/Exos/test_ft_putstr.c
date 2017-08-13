#include "header.h"
#include <stdio.h>
int     main(int argc, char **argv)
{
    //printf("GO");
    if (argc < 2)
        return(0);
    ft_putstr(argv[1]);
    return(0);
}
