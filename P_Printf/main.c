/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:20:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/20 14:28:11 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int d = 5;
	// ft_printf("%2d", d);
	// printf("\n");
	// printf("%2d", d);
	printf(" %d ", ft_printf("%2d", d));
	printf("\n");
	printf(" %d ", printf("%2d", d));
	printf("\n");
}
