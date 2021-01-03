#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int d = 3;
	int lol = 20;
	char c = 'a';
	char *str = "lol";

	c = d;
	ft_printf("FT_PRINTF == : %%p = %-15p %%d = %-20d", str, d);
	printf("\nPRINTF ===== : %%p = %-15p %%d = %*d\n", str, lol, d);
	return (0);
}
