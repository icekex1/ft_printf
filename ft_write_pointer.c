/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:10 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 11:57:12 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_p_right(t_flags chart, int counter, unsigned long n)
{
	if (chart.min_field_width > 0)
	{
		if (chart.hashtag)
			chart.min_field_width -= 2;
		counter += mfw(chart, x_length(n), n, ' ');
	}
	counter += hashtag(0);
	if (n == 0)
		ft_putchar_fd('0', 1);
	else
		ft_puthexa(n);
	counter += x_length(n);
	return (counter);
}

int	print_p_left(t_flags chart, va_list parameters)
{
	unsigned long	n;
	int				counter;

	n = va_arg(parameters, unsigned long);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.hashtag)
			counter += hashtag(0);
		if (n == 0)
			ft_putchar_fd('0', 1);
		else
			ft_puthexa(n);
		counter += x_length(n);
		if (chart.min_field_width > 0)
			counter += mfw(chart, x_length(n) + 2, n, ' ');
	}
	else
		counter = print_p_right(chart, counter, n);
	return (counter);
}
