#include "header.h"
#include <stdlib.h>

char	*al_print_comb(void)
{
	char i;
	char j;
	char k;
	char *ret = malloc(sizeof(char) * 1000);
	int n = 0;

	i = '0';
	j = '0';
	k = '0';

	while (i <= '9')
	{
		j = i + 1;
		while (j <= '9')
		{
			k = j + 1;
			while (k <= '9')
			{
				ret[n] = i;
				n++;
				ret[n] = j;
				n++;
				ret[n] = k;
				n++;
				if (!(i == '7' && j == '8' && k == '9'))
				{
					ret[n] = ',';
					n++;
					ret[n] = ' ';
					n++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	ret [n] = '\0';
	return (ret);
}