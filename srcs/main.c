#include "libftprintf.h"
#include <stdio.h>

int main()
{
//	int		a = -4;
//	int		b = 0;
//	char	c = 'a';
/*	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";*/

	printf("\t%d\n", printf("%lX", 4294967284));
	printf("\t%d\n", ft_printf("%X", 4294967284));
	return 0;
}
