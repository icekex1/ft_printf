/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:56:51 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:39:08 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	print_u_right(t_flags chart, int counter, long n)
{
	if (chart.min_field_width > 0)
	{
		if (n == 0 && chart.precision == 0)
			chart.min_field_width++;
		if (chart.zero == 1 && n < 0 && chart.dot == 0)
		{
			chart.min_field_width--;
			ft_putchar_fd('-', 1);
			counter++;
			n *= -1;
		}
		if (chart.zero == 1 && chart.dot == 0)
			counter += mfw(chart, d_length(n), n, '0');
		else
			counter += mfw(chart, d_length(n), n, ' ');
	}
	counter += precision(chart, d_length(n));
	counter += print_nothing(chart, n);
	if (n == 0 && chart.precision == 0)
		chart.min_field_width++;
	return (counter);
}

int	print_u_left(t_flags chart, va_list parameters)
{
	long	n;
	long	counter;

	n = va_arg(parameters, unsigned int);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.dot)
			counter += precision(chart, d_length(n));
		counter += print_nothing(chart, n);
		if (n == 0 && chart.precision == 0)
			chart.min_field_width++;
		if (chart.min_field_width > 0)
			counter += mfw(chart, d_length(n), n, ' ');
	}
	else
		counter += print_u_right(chart, counter, n);
	return (counter);
}
