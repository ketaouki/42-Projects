#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int c = 0;

	//ft_printf("FT_PRINTF == : %*c%*c", -10, '0', 1, '1');
	//printf("\nPRINTF ===== : %*c%*c\n", -10, '0', 1, '1');

//ft_printf("FT_PRINTF == : %*c", -10, '0');
//printf("\nPRINTF ===== : %*c", -10, '0');
	printf(" == %d\n", 	ft_printf("-%-2c * -%2c* ", 0, 0));
	printf(" == %d\n", 	printf("-%-2c * -%2c* ", 0, 0));
	return (0);
}
