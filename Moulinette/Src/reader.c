#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*ft_strdmp(char *tab, int size)
{
	char	*tab2;
	int		n;

	n = 0;
	while (tab[n])
		n++;
	tab2 = malloc((size + n) * sizeof(char));
	n = 0;
	while (tab[n])
	{
		tab2[n] = tab[n];
		n++;
	}
	free(tab);
	return (tab2);
}

char	*ft_read_file(void)
{
	char	*tab;
	char	buf[1];
	int		i;
	int		size;

	size = 1;
	i = 0;
	tab = malloc(2 * sizeof(char) + 1);
	while (read(0, buf, 1))
	{
		if (i >= size)
		{

			tab[i] = '\0';
			size = size * 2;
			tab = ft_strdmp(tab, size);
		}
		tab[i] = buf[0];
		i++;
	}
	tab[i] = '\0';
    i = 0;
	return (tab);
}
