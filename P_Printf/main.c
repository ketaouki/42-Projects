/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 14:32:07 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf(" %d ", ft_printf("%010.0d", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", printf("%010.0d", UINT_MAX + 1));
	// printf("\n");

	// printf("\n TEST\n");
	// printf(" %d ", printf("%05.3d", 10));
	// printf("\n");

	// printf("\n TEST 1\n");
	// printf(" %d ", ft_printf(" %p ", -1));
	// printf("\n");
	// printf(" %d ", printf(" %p ", -1));

	printf("\n TEST 3\n");
	printf(" %d ", ft_printf(" *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10));
	printf("\n");
	printf(" %d ", printf(" *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10));

	// printf("\n TEST 6\n");

	// printf(" %d ", ft_printf(" %10p %10p ", 1, -1));
	// printf("\n");
	// printf(" %d ", printf(" %10p %10p ", 1, -1));

	// printf("\n TEST 32\n");

	// printf(" %d ", ft_printf("%.4s", ""));
	// printf("\n");
	// printf(" %d ", printf("%.4s", ""));


	// printf("\n TEST 61\n");
	// printf(" %d ", printf("%010.0d", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%010.0d", UINT_MAX + 1));

	// printf("\n TEST 65\n");
	// printf(" %d ", printf("%011.0d", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%011.0d", UINT_MAX + 1));

	// printf("\n TEST 69\n");
	// printf(" %d ", printf("%.0d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%.0d", 0));

	// printf("\n TEST 72\n");
	// printf(" %d ", printf("%1.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%1.d", 0));

	// printf("\n TEST 73\n");
	// printf(" %d ", printf("%2.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%2.d", 0));

	// printf("\n TEST 74\n");
	// printf(" %d ", printf("%3.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%3.d", 0));

	return (0);
}
