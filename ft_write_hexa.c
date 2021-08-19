/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:17 by tzeck             #+#    #+#             */
/*   Updated: 2021/08/19 11:57:19 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	x_length(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

void	zero_case(long n, int b, t_flags chart)
{
	if (n == 0 && (chart.precision > 0 || !chart.dot))
		ft_putchar_fd('0', 1);
	if (chart.min_field_width && chart.dot && chart.precision <= 0)
		ft_putchar_fd(' ', 1);
	else
	{
		if (b == 0)
			ft_puthexa(n);
		else
			ft_putheXa(n);
	}
}

int	print_x_right(t_flags chart, int counter, long n, int b)
{
	if (chart.min_field_width > 0)
	{
		if (chart.zero == 1 && chart.hashtag && chart.dot == 0)
		{
			chart.min_field_width -= 2;
			counter += hashtag(b);
		}
		else if (chart.hashtag)
			chart.min_field_width -= 2;
		if (chart.zero == 1 && chart.dot == 0)
			counter += mfw(chart, x_length(n), n, '0');
		else
			counter += mfw(chart, x_length(n), n, ' ');
	}
	if (chart.hashtag && !chart.zero && n != 0)
		counter += hashtag(b);
	counter += precision(chart, x_length(n));
	zero_case(n, b, chart);
	counter += x_length(n);
	return (counter);
}

int	print_x_left(t_flags chart, va_list parameters, int b)
{
	unsigned long	n;
	int				counter;

	n = va_arg(parameters, unsigned int);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.hashtag && n != 0)
			counter += hashtag(b);
		if (chart.dot && chart.min_field_width && chart.precision)
			counter += precision(chart, x_length(n));
		else if (chart.dot)
			counter += precision(chart, x_length(n) - 1);
		zero_case(n, b, chart);
		counter += x_length(n);
		if (chart.min_field_width > 0)
			counter += mfw(chart, x_length(n), n, ' ');
	}
	else
		counter += print_x_right(chart, counter, n, b);
	return (counter);
}
