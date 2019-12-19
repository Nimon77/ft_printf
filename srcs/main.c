#include "../include/libftprintf.h"

int main()
{
	unsigned int uint = 4294967295;

	printf("%0.6d%c%s%u\n", 12, 'z', "Bonjour, c'est un test", uint);
	ft_printf("%d%c%s%u\n", 12, 'z', "Bonjour, c'est un test", uint);
	return 0;
}
