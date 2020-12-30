#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str;
	char c;
	int d;
	int t;

	d = -10;
	t = 3;
	c = 'a';
	str = "aaze";
	ft_printf("ft_printf c = %c, s = %s, p = %p, d = %d, i = %i, u = %u, x = %x, X = %X, %%", c , str, str, d, d, d, d, d);
	printf("\nprintf    c = %c, s = %s, p = %p, d = %d, i = %i, u = %u, x = %x, X = %X, %%\n", c , str, str, d, d, d, d, d);


	//ft_printf("%p", str);


	//printf("\n%x\n", (unsigned int)str);
	//printf("\n%p", str);
	//printf("%d\n", *str);

	return (0);
}
