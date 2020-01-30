#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf("-%.*d-", -5, 'a'));
	printf("\t%d\n", ft_printf("-%.*d-", -5, 'a'));
	free(test);
	return 0;
}
