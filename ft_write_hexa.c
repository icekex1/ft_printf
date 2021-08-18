/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:41:03 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 09:42:16 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexa_length(unsigned long n)
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

void	ft_zero_case(long n, int b)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	else
	{
		if (b == 0)
			ft_puthexa(n);
		else
			ft_putheXa(n);
	}
}

int	ft_print_hex_right(t_flags chart, int counter, long n, int b)
{
	if (chart.min_field_width > 0)
	{
		if (chart.zero == 1 && chart.hashtag && chart.dot == 0)
		{
			chart.min_field_width -= 2;
			counter += ft_hashtag(b);
		}
		else if (chart.hashtag)
			chart.min_field_width -= 2;
		if (chart.zero == 1 && chart.dot == 0)
			counter += ft_min_field_width(chart, ft_hexa_length(n), n, '0');
		else
			counter += ft_min_field_width(chart, ft_hexa_length(n), n, ' ');
	}
	if (chart.hashtag && !chart.zero && n != 0)
		counter += ft_hashtag(b);
	counter += ft_precision(chart, ft_hexa_length(n));
	ft_zero_case(n, b);
	counter += ft_hexa_length(n);
	return (counter);
}

int	ft_print_hex_left(t_flags chart, va_list parameters, int b)
{
	unsigned long	n;
	int				counter;

	n = va_arg(parameters, unsigned int);
	counter = 0;
	if (chart.minus == 1)
	{
		if (chart.hashtag && n != 0)
			counter += ft_hashtag(b);
		if (chart.dot)
			counter += ft_precision(chart, ft_hexa_length(n) - 1);
		ft_zero_case(n, b);
		counter += ft_hexa_length(n);
		if (chart.min_field_width > 0)
			counter += ft_min_field_width(chart, ft_hexa_length(n), n, ' ');
	}
	else
		counter += ft_print_hex_right(chart, counter, n, b);
	return (counter);
}
