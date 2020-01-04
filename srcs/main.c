#include "libftprintf.h"

int main()
{
	unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(test));
	printf("%c\t%s\t%p\t%d\t%i\t%u\n", 'c', "test", NULL, 4552342, 5453, uint);
	ft_printf("%c\t%s\t%p\t%d\t%i\t%u\n", 'c', "test", NULL, 4552342, 5453,
			uint);
	free(test);
	return 0;
}
