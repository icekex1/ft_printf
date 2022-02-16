/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:57:26 by tzeck             #+#    #+#             */
/*   Updated: 2022/02/16 16:58:17 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	d_length(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	negative_number(long *n, int counter)
{
	ft_putchar_fd('-', 1);
	counter++;
	*n *= -1;
	return (counter);
}

int	print_nothing(t_flags chart, long n)
{
	int	counter;

	counter = 0;
	if (chart.precision == 0 && n == 0)
		return (counter);
	else
	{
		ft_putnbr_fd(n, 1);
		counter += d_length(n);
	}
	return (counter);
}

int	print_d_right(t_flags chart, int counter, long n)
{
	if (chart.min_field_width > 0)
	{
		if (n == 0 && chart.precision == 0)
			chart.min_field_width++;
		if (chart.zero == 1 && n < 0 && chart.dot == 0)
		{
			counter = negative_number(&n, counter);
			chart.min_field_width--;
		}
		if (chart.zero == 1 && chart.dot == 0)
			counter += mfw(chart, d_length(n), n, '0');
		else
			counter += mfw(chart, d_length(n), n, ' ');
	}
	if (chart.plus || chart.space)
		counter += plus_space(chart, n);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		counter++;
		n *= -1;
	}
	counter += precision(chart, d_length(n));
	counter += print_nothing(chart, n);
	return (counter);
}

int	print_d_left(t_flags chart, va_list parameters)
{
	long	n;
	int		counter;

	n = va_arg(parameters, int);
	counter = 0;
	if (chart.minus == 1)
	{
		if (n < 0)
		{
			counter = negative_number(&n, counter);
			chart.min_field_width--;
		}
		if (chart.plus || chart.space)
			counter += plus_space(chart, n);
		if (chart.dot)
			counter += precision(chart, d_length(n));
		counter += print_nothing(chart, n);
		if (n == 0 && chart.precision == 0)
			chart.min_field_width++;
		if (chart.min_field_width > 0)
			counter += mfw(chart, d_length(n), n, ' ');
	}
	else
		counter = print_d_right(chart, counter, n);
	 return (counter);
}
