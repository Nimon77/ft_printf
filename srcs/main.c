#include "../include/libftprintf.h"

int main()
{
	unsigned int uint = 4294967295;

	printf("%12.3d %c %s %13.12u\n", 12, 'z', "Bonjour, c'est un test",
			uint);
	ft_printf("%12.3d %c %s %13.12u", 12, 'z', "Bonjour, c'est un test",
			uint);
	return 0;
}
