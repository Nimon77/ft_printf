#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf("-%5c-", 'a'));
	printf("\t%d\n", ft_printf("-%5c-", 'a'));
	free(test);
	return 0;
}
