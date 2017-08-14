#include "header.h"
#include <stdlib.h>

char	*al_print_comb2(void)
{
	int a;
	int b;
	char *ret = malloc(sizeof(char) * 100000);
	int n = 0;
	a = 0;

	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ret[n] = (a / 10 + '0');
			n++;
			ret[n] = (a % 10 + '0');
			n++;
			ret[n] = (' ');
			n++;
			ret[n] = (b / 10 + '0');
			n++;
			ret[n] = (b % 10 + '0');
			n++;
			if (!(a == 98 && b == 99))
			{
				ret[n] = (',');
				n++;
				ret[n] = (' ');
				n++;
			}
			b++;
		}
		a++;
	}
	ret [n] = '\0';
	return (ret);
}
