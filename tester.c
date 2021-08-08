/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:37:33 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/06 10:34:42 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <stdarg.h>

void test(va_list args)
{
	printf("%d", va_arg(args, int));
}

void not_main(int n, ...)
{
	n = 3;
	va_list args;
	va_start(args, n);
	printf("%d", va_arg(args, int));
	test(args);
	printf("%d", va_arg(args, int));
	va_end(args);
}

int	main()
{
	printf("%+ d", 567);
	return (1);
}