#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int d = 0;

	ft_printf("FT_PRINTF == : %.d", d);
	printf("\nPRINTF ===== : %.d", d);

	//printf("%d == \n", ft_printf("%.d", d));
	//printf("%d == \n", printf("%.d", d));
	return (0);
}
