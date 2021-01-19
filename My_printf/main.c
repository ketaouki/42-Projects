/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:15:17 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/19 13:40:33 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int d;
	int dd;

	dd = 10;
	d = 20;
	printf("%d", ft_printf(" %-3.d %10.42d ", d, dd));
	printf("\n");
	printf("%d",  printf(" %3.d %10.42d ", d, dd));
	printf("\n");
	return (0);
}
