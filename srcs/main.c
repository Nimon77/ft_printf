#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;
	int 	r00 = 0;

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf("%f"));
	printf("\t%d\n", ft_printf("%f"));
	free(test);
	return 0;
}
