/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/03 10:31:56 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("\n TEST 9\n");
	printf(" %d ", ft_printf("%.p", 0));
	 printf("\n");
	printf(" %d ", printf("%.p", 0));

 	// printf("\n TEST 9\n");
	// printf(" %d ", ft_printf(" *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10));
	//  printf("\n");
	// printf(" %d ", printf(" *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10));

	// printf("\n TEST 10\n");
	// printf(" %d ", ft_printf(" *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101));
	// printf("\n");
	// printf(" %d ", printf(" *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101));

	// printf("\n TEST 11\n");

	// printf(" %d ", ft_printf(" *%*.*u* *%*.*u* ", -6, 2, 102, 10, 21, 101));
	// printf("\n");
	// printf(" %d ", printf(" *%*.*u* *%*.*u* ", -6, 2, 102, 10, 21, 101));

	// printf("\n TEST 12\n");

	// printf(" %d ", ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101));
	// printf("\n");
	// printf(" %d ", printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101));

	// dprintf(1, "\n TEST 13\n");

	// printf(" %d ", ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));
	// printf("\n");
	// printf(" %d ", printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));



	// printf("\n TEST 16\n");
	// printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));
	// printf("\n");
	// printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));

	// printf("\n TEST 18\n");
	// printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	// printf("\n");
	// printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));

	// printf("\n TEST 57\n");
	// printf(" %d ", printf("%09.0u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%09.0u", UINT_MAX + 1));

	// printf("\n TEST 59\n");
	// printf(" %d ", printf("%09.2u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%09.2u", UINT_MAX + 1));

	// printf("\n TEST 67\n");
	// printf(" %d ", printf("%011.2u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%011.2u", UINT_MAX + 1));

	return (0);
}
