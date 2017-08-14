#include "header.h"
#include <stdlib.h>

char	*al_print_combn(int n)
{
	int	tab[n];
	int	i;
	int col;
	char *ret = malloc(sizeof(char) * 100000);
	int k = 0;

	col = n - 1;
	if (n > 10)
		return NULL;
	i = 0;
	while (i <= n)
	{
		tab[i] = i;
		i++;
	}
	i = 0;
	while (i < n)
	{
		ret[k] = (tab[i] + '0');
		k++;
		i++;
	}
	int	j = 0;

	while (1)
	{
		while (tab[col] == (9 + col - (n - 1)) && col >= 0)
			col--;
		if (col < 0)
			break ;
		tab[col]++;
		j = col + 1;
		while (j <= n)
		{
			tab[j] = tab[j - 1] + 1;
			j++;
		}
		col = n - 1;
		ret[k] = (',');
		k++;
		ret[k] = (' ');
		k++;
		i = 0;
		while (i < n)
		{
			ret[k] = (tab[i] + '0');
			k++;
			i++;
		}
	}
	ret[k] = '\0';
	return (ret);
}
