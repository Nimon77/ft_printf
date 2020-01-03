#include "libftprintf.h"

int main()
{
	unsigned int uint = 4294967295;

	printf("%p\n", &uint);
	ft_printf("%p", &uint);
	return 0;
}
