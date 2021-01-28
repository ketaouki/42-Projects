/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/28 10:03:02 by ketaouki         ###   ########lyon.fr   */
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

	printf("\n TEST 57\n");
	printf(" %d ", printf("%10.0d", UINT_MAX));
	printf("\n");
	printf(" %d ", ft_printf("%10.0d", UINT_MAX));

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
