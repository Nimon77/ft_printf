#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf("-->|%-4.*d|<--", 0, 0));
	printf("\t%d\n", ft_printf("-->|%-4.*d|<--", 0, 0));
	free(test);
	return 0;
}
