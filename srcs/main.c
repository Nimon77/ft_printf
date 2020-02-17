#include "libftprintf.h"

int main(void)
{
	int u = 40;

	printf("test %p\n", &u);
	ft_printf("test %p", &u);
}