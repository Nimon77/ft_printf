#include "libftprintf.h"

int main()
{
	unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(test));
	printf("%p\t%p\n", &uint, &test);
	ft_printf("%p\t%p", &uint, &test);
	return 0;
}
