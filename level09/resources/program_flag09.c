#include <stdio.h>

int main(int ac, char **av)
{
	int i = -1;
	char str[10000];

	bzero(str, 10000);
	while (av[1][++i])
		str[i] = av[1][i] - i;
	printf("La solution frerot c'est -> %s\n", str);
	return (0);
}
