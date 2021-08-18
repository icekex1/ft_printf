/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:18:02 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/18 11:32:25 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_i_d_length(long n)
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

int	ft_print_d_i_right(t_flags chart, int counter, long n)
{
	if (chart.min_field_width > 0)
	{
		if (chart.zero == 1 && n < 0 && chart.dot == 0)
		{
			counter = negative_number(&n, counter);
			chart.min_field_width--;
		}
		if (chart.zero == 1 && chart.dot == 0)
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, '0');
		else
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, ' ');
	}
	if (chart.plus || chart.space)
		counter += ft_plus_space(chart, n);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		counter++;
		n *= -1;
	}
	counter += ft_precision(chart, ft_i_d_length(n));
	ft_putnbr_fd(n, 1);
	counter += ft_i_d_length(n);
	return (counter);
}

int	ft_print_d_i_left(t_flags chart, va_list parameters)
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
			counter += ft_plus_space(chart, n);
		if (chart.dot)
			counter += ft_precision(chart, ft_i_d_length(n));
		ft_putnbr_fd(n, 1);
		counter += ft_i_d_length(n);
		if (chart.min_field_width > 0)
			counter += ft_min_field_width(chart, ft_i_d_length(n), n, ' ');
	}
	else
		counter = ft_print_d_i_right(chart, counter, n);
	 return (counter);
}
