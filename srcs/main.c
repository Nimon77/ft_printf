#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//unsigned int uint = 4294967295;
	char	*test;
	char	*print = "-->|%-4.*d|<--";

	test = (char *)malloc(sizeof(*test));
	printf("\t%d\n", printf(print, 2, -135));
	printf("\t%d\n", ft_printf(print, 2, -135));
	free(test);
	return 0;
}
