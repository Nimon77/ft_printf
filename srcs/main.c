#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf("-->|%%|<--"));
	printf("\t%d\n", ft_printf("-->|%%|<--"));
	free(test);
	return 0;
}
