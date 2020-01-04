#include "libftprintf.h"
#include <stdio.h>

int main()
{
	unsigned int uint = 4294967295;
	char	*test;

	test = (char *)malloc(sizeof(test));
	printf("%c\t%s\t%p\t%d\t%i\t%u\t%x\t%X\n", '\0', "\0", NULL, 4552342,
			5453, uint, 0xFF5364, 0x26B78C9);
	ft_printf("%c\t%s\t%p\t%d\t%i\t%u\t%x\t%X", '\0', "\0", NULL, 4552342,
		   5453, uint, 0xFF5364, 0x26B78C9);
	free(test);
	return 0;
}
