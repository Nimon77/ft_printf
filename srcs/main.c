#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(*test));
	printf("\n%d\n", printf("-%20.5d-", 4552342));
	printf("\n%d\n", ft_printf("-%20.5d-", 4552342));
	free(test);
	return 0;
}
