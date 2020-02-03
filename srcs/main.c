#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;
	char	*print = "-->|%*.1i|<--";

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf(print, -4, 13));
	printf("\t%d\n", ft_printf(print, -3, 13));
	free(test);
	return 0;
}
